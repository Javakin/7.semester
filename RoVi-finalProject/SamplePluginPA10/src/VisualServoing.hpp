


// RobWork includes
#include <rw/models/WorkCell.hpp>
#include <rw/kinematics/State.hpp>
#include <rwlibs/opengl/RenderImage.hpp>
#include <rwlibs/simulation/GLFrameGrabber.hpp>
#include <rw/kinematics/MovableFrame.hpp>

#include <rw/math.hpp> // Pi, Deg2Rad
#include <rw/math/Q.hpp>
#include <rw/math/Transform3D.hpp>
#include <rw/math/RPY.hpp>
#include <rw/math/Vector3D.hpp>
#include <rw/math/EAA.hpp>
#include <rw/math/Jacobian.hpp>


#include <rw/loaders/ImageLoader.hpp>
#include <rw/loaders/WorkCellFactory.hpp>
//#include <rw/rw.hpp>

// RobWorkStudio includes
#include <RobWorkStudioConfig.hpp> // For RWS_USE_QT5 definition
#include <rws/RobWorkStudioPlugin.hpp>
#include <rws/RobWorkStudio.hpp>

// OpenCV 3
#include <opencv2/opencv.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#ifndef VISUALSERVOING
#define VISUALSERVOING



using namespace rw::common;
using namespace rw::graphics;
using namespace rw::kinematics;
using namespace rw::loaders;
using namespace rw::models;
using namespace rw::sensor;
using namespace rw::math;

using namespace rwlibs::opengl;
using namespace rwlibs::simulation;

using namespace std;
using namespace rws;
using namespace cv;

class VisualServoing{
public:
    VisualServoing(rw::common::LogWriter &lout, rw::models::WorkCell::Ptr _wc, State& _worldState):log(lout) {
        this->_wc = _wc;
        this->_state = &_worldState;
        Device::Ptr device;
        device = _wc->findDevice("PA10");
        if (device == NULL){
            log << "read of device failed\n";
        }
        qOld = device->getQ(*_state);

    }
    ~VisualServoing(){
        delete jImageJacobian;
    }

    void setImageJacobian(double F, double Z, VelocityScrew6D<> U) {
        // calculate and set the image Jacobian for three points
        jImageJacobian = new Jacobian(6,6);
        Jacobian &J(*jImageJacobian);
        for (int i = 0; i < 3; i++) {
            J(2 * i, 0) = -F / Z;
            J(2 * i, 1) = 0;
            J(2 * i, 2) = U[i*2] / Z;
            J(2 * i, 3) = U[i*2] * U[i*2+1] / F;
            J(2 * i, 4) = -(F * F + U[i*2] * U[i*2]) / F;
            J(2 * i, 5) = U[i*2+1];


            J(1 + 2 * i, 0) = 0;
            J(1 + 2 * i, 1) = -F / Z;
            J(1 + 2 * i, 2) = U[i*2+1] / Z;
            J(1 + 2 * i, 3) = (F * F + U[i*2+1] * U[i*2+1]) / F;
            J(1 + 2 * i, 4) = -U[i*2] * U[i*2+1] / F;
            J(1 + 2 * i, 5) = -U[i*2];
        }
        UV=U;

    }
    void setImageJacobian1(double F, double Z){
        // calculate and set the image Jacobian for three points
        jImageJacobian = new Jacobian(2,2);
        Jacobian &J(*jImageJacobian);

        J(0, 0) = -F / Z;
        J(0, 1) = 0;

        J(1, 0) = 0;
        J(1, 1) = -F / Z;
    }

    Q nextQ(VelocityScrew6D<> points, double dt){
        dt= dt/1000;
        points = points-UV;
        Frame* cameraFrame = _wc->findFrame("CameraSim");
        Device::Ptr device;
        device = _wc->findDevice("PA10");
        if (device == NULL){
            log << "read of device failed\n";
        }

        Transform3D<> baseToTool = device->baseTframe(cameraFrame, *_state);

        Jacobian S_q(Rotation3D<>(baseToTool.R().e().transpose()));

        Jacobian J_q = device->baseJframe(cameraFrame, *_state);

        Jacobian J = *jImageJacobian*S_q*Jacobian(J_q.e()*J_q.e().transpose());

        Jacobian jInv = Jacobian(J.e().inverse()*J_q.e());




        //log << "J_p output: \n" << jInv << endl;


        Q dq = (Jacobian(jInv.e().transpose())*points);
        Q q0 = device->getQ(*_state);




        log << "dQ: " << dq << endl;
        log << "q0: " << q0 << endl;

        // Positional limit
        Q v_limit = device->getVelocityLimits();
        Q a_limit = device->getAccelerationLimits();
        pair<Q,Q> bounds = device->getBounds();


        Q q_max(7, 1000,1000,1000,1000,1000,1000,1000);
        Q q_min = q_max*-1;
        double  scale=1;
        for (unsigned int i = 0; i <7; i++){
            // possitional limi
            if (q_min[i] < bounds.first[i]){
                q_min[i] = bounds.first[i];
            }
            if (q_max[i] > bounds.second[i]){
                q_max[i] = bounds.second[i];
            }
            // velocity limit
            if(q_min[i] < -v_limit[i]*dt+q0[i]){
                q_min[i] = -v_limit[i]*dt+q0[i];
            }
            if(q_max[i] > v_limit[i]*dt+q0[i]){
                q_max[i] = v_limit[i]*dt+q0[i];
            }
            // acceleration limti
            if(q_min[i] < -0.5*a_limit[i]*dt*(2*dt)+q0[i] + (q0[i]-qOld[i])){
                q_min[i] = -0.5*a_limit[i]*dt*(2*dt)+q0[i] + (q0[i]-qOld[i]);
            }
            if(q_max[i] > 0.5*a_limit[i]*dt*(2*dt)+q0[i] + (q0[i]-qOld[i])){
                q_max[i] = 0.5*a_limit[i]*dt*(2*dt)+q0[i] + (q0[i]-qOld[i]);
            }
            if(dq[i]>0) {
                if (scale > (q_max[i] - q0[i]) / (dq[i])) {
                    scale = (q_max[i] - q0[i]) / (dq[i]);
                }
            }
            else if(dq[i]<0){
                if (scale > (q_min[i] - q0[i]) / (dq[i])) {
                    scale = (q_min[i] - q0[i]) / (-dq[i]);
                }
            }

        }
        log << "q_max: " << q_max << endl;
        log << "q_min: " << q_min << endl;
        log << "Scale: " << scale << endl;
        log << "q_new: " << q0+(dq*scale) << endl;

        // cap speeds







        Q qOutPut = q0+dq;

        log << "outputQ; "<< qOutPut << endl;

        qOld = qOutPut;

        return qOutPut;

    }

    Jacobian vecTJac(vector<double> src){
        // bla
        Jacobian J(src.size(), 1);
        for (unsigned int i  = 0; i<src.size(); i++){
            J(i,0) = src[i];
        }

        return J;
    }




private:
    rw::kinematics::State* _state;
    rw::models::WorkCell::Ptr _wc;
    rw::common::LogWriter &log;
    Jacobian* jImageJacobian;
    VelocityScrew6D<> UV;
    Q qOld;
};

#endif // VISUALSERVOING













