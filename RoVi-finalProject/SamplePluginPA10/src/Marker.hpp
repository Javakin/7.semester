


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

#ifndef MARKER
#define MARKER

#define MARKER1     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker1.ppm"

#define MARKER2A    "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker2a.ppm"
#define MARKER2B    "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker2b.ppm"
#define MARKER3     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker3.ppm"

#define SLOWSEQ     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/motions/MarkerMotionSlow.txt"
#define MEDISEQ     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/motions/MarkerMotionMedium.txt"
#define FASTSEQ     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/motions/MarkerMotionFast.txt"



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

class Marker{
public:
    Marker(rw::common::LogWriter &lout):log(lout){}
    Marker(rwlibs::opengl::RenderImage *_textureRender,rw::common::LogWriter &lout):log(lout){
        //setup texture render
        this->_textureRender = _textureRender;
        //lout << "I am here" << endl;
    }
    void setImage(string sFilePath){
        // load and place marker image
        Image::Ptr image;
        image = ImageLoader::Factory::load(sFilePath);
        _textureRender->setImage(*image);

    }
    void setMarker(rw::models::WorkCell::Ptr _wc){
        MarkerFrame = _wc->findFrame<MovableFrame>("Marker");

    }
    void setState(State* worldState){
        _state = worldState;
    }
    void setLout(){

    }

    void moveMarker(){
        // move the market to the position given the position number
        if (MarkerPath.size()>iPosNum)
            MarkerFrame->setTransform(MarkerPath[iPosNum++], *_state);
        else iPosNum = 0;

    }

    void importPath(string aFilePath){
        // get the path form selected filepath and place it in the MarkerPath variable
        float num[6];
        ifstream myfile(aFilePath);
        if (myfile.is_open())
        {
            while (!myfile.eof()) {
                for (int i = 0; i < 6; i++) {
                    myfile >> num[i];
                    //log << num[i] << "\t";
                }
                //log << endl;
                Vector3D<> vec(num[0],num[1],num[2]);
                RPY<> ang(num[3],num[4],num[5]);
                MarkerPath.push_back(Transform3D<>(vec, ang.toRotation3D()));
            }
            myfile.close();
        }

        log << "importing path finished." << endl;
    }

    Transform3D<> getPosition(){
        // return the imeage transform
        return MarkerPath[iPosNum];
    }


private:
    rwlibs::opengl::RenderImage *_textureRender;
    vector<Transform3D<> > MarkerPath;
    MovableFrame* MarkerFrame;
    rw::kinematics::State* _state;
    unsigned int iPosNum;
    rw::common::LogWriter &log;

};

#endif // MARKER













