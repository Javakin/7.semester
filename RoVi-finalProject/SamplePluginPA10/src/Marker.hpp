


// RobWork includes
#include <rw/models/WorkCell.hpp>
#include <rw/kinematics/State.hpp>
#include <rwlibs/opengl/RenderImage.hpp>
#include <rwlibs/simulation/GLFrameGrabber.hpp>

// RobWorkStudio includes
#include <RobWorkStudioConfig.hpp> // For RWS_USE_QT5 definition
#include <rws/RobWorkStudioPlugin.hpp>

#include <rws/RobWorkStudio.hpp>

#include <rw/loaders/ImageLoader.hpp>
#include <rw/loaders/WorkCellFactory.hpp>

// OpenCV 3
#include <opencv2/opencv.hpp>

#include <string>

#ifndef MARKER
#define MARKER

#define MARKER1     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker1.ppm"

#define MARKER2A    "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker2a.ppm"
#define MARKER2B    "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker2b.ppm"
#define MARKER3     "/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker3.ppm"


using namespace rw::common;
using namespace rw::graphics;
using namespace rw::kinematics;
using namespace rw::loaders;
using namespace rw::models;
using namespace rw::sensor;
using namespace rwlibs::opengl;
using namespace rwlibs::simulation;

using namespace std;
using namespace rws;
using namespace cv;

class Marker{
public:
    Marker(){}
    Marker(rwlibs::opengl::RenderImage *_textureRender){
        //setup texture render
        this->_textureRender = _textureRender;
    }
    void setImage(string sFilePath){
        // load and place marker image
        Image::Ptr image;
        image = ImageLoader::Factory::load(sFilePath);
        _textureRender->setImage(*image);

    }


private:
    rwlibs::opengl::RenderImage *_textureRender;
};

#endif // MARKER

