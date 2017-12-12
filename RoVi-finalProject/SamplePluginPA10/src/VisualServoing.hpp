


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

    }
    ~VisualServoing(){
        delete jImageJacobian;
    }

    void setImageJacobian(double F, double Z, double U[3], double V[3]) {
        // calculate and set the image Jacobian for three points
        jImageJacobian = new Jacobian(6,6);
        Jacobian &J(*jImageJacobian);
        for (int i = 0; i < 3; i++) {
            J(2 * i, 0) = -F / Z;
            J(2 * i, 1) = 0;
            J(2 * i, 2) = U[i] / Z;
            J(2 * i, 3) = U[i] * V[i] / F;
            J(2 * i, 4) = -(F * F + U[i] * U[i]) / F;
            J(2 * i, 5) = V[i];


            J(1 + 2 * i, 0) = 0;
            J(1 + 2 * i, 1) = -F / Z;
            J(1 + 2 * i, 2) = V[i] / Z;
            J(1 + 2 * i, 3) = (F * F + V[i] * V[i]) / F;
            J(1 + 2 * i, 4) = -U[i] * V[i] / F;
            J(1 + 2 * i, 5) = -U[i];
        }

        log << "2x2 jacobian\n" << J << endl;

    }
    void setImageJacobian1(double F, double Z){
        // calculate and set the image Jacobian for three points
        jImageJacobian = new Jacobian(2,2);
        Jacobian &J(*jImageJacobian);

        J(0, 0) = -F / Z;
        J(0, 1) = 0;

        J(1, 0) = 0;
        J(1, 1) = -F / Z;


        log  << "2x2 jacobian\n" << J << endl;
    }




private:
    rw::kinematics::State* _state;
    rw::models::WorkCell::Ptr _wc;
    rw::common::LogWriter &log;
    Jacobian* jImageJacobian;
};

#endif // VISUALSERVOING













