#include "SamplePlugin.hpp"

#include <rws/RobWorkStudio.hpp>

#include <QPushButton>

#include <rw/loaders/ImageLoader.hpp>
#include <rw/loaders/WorkCellFactory.hpp>
#include <rw/kinematics/MovableFrame.hpp>

#include <functional>




#define DELTA_T      100         // period in ms
#define Z_COORDINAT  0.5         // the debth of the image in meters
#define FOCALLENGTH  823        // focal lehgth of the camera
#define POINTS       3



using namespace rw::common;
using namespace rw::graphics;
using namespace rw::kinematics;
using namespace rw::loaders;
using namespace rw::models;
using namespace rw::sensor;
using namespace rwlibs::opengl;
using namespace rwlibs::simulation;

using namespace rws;

using namespace cv;

using namespace std::placeholders;

SamplePlugin::SamplePlugin():
    RobWorkStudioPlugin("SamplePluginUI", QIcon(":/pa_icon.png")),SURFObj(400)
{
	setupUi(this);

	_timer = new QTimer(this);
    _markerMover = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(timer()));
    connect(_markerMover, SIGNAL(timeout()), this, SLOT(markerTimer()));

	// now connect stuff from the ui component
	connect(_btn0    ,SIGNAL(pressed()), this, SLOT(btnPressed()) );
	connect(_btn1    ,SIGNAL(pressed()), this, SLOT(btnPressed()) );
	connect(_spinBox  ,SIGNAL(valueChanged(int)), this, SLOT(btnPressed()) );

	Image textureImage(300,300,Image::GRAY,Image::Depth8U);
	_textureRender = new RenderImage(textureImage);

    // setup markerhandle
    myMarker = new Marker(_textureRender,log().info(),(double)FOCALLENGTH);
    myMarker->importPath(FASTSEQ);


	Image bgImage(0,0,Image::GRAY,Image::Depth8U);
	_bgRender = new RenderImage(bgImage,2.5/1000.0);
	_framegrabber = NULL;
}

SamplePlugin::~SamplePlugin()
{
    delete _textureRender;
    delete _bgRender;
    delete myMarker;
	delete myViscServ;
}

void SamplePlugin::initialize() {
	log().info() << "INITALIZE" << "\n";

	getRobWorkStudio()->stateChangedEvent().add(std::bind(&SamplePlugin::stateChangedListener, this, _1), this);

	// Auto load workcell
    WorkCell::Ptr wc = WorkCellLoader::Factory::load("/home/student/Desktop/7.semester/RoVi-finalProject/PA10WorkCell/ScenePA10RoVi1.wc.xml");
	getRobWorkStudio()->setWorkCell(wc);

	// Load Lena image
	Mat im, image;
    im = imread("/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/src/lena.bmp", CV_LOAD_IMAGE_COLOR); // Read the file
	cvtColor(im, image, CV_BGR2RGB); // Switch the red and blue color channels
	if(! image.data ) {
		RW_THROW("Could not open or find the image: please modify the file path in the source code!");
	}
	QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888); // Create QImage from the OpenCV image
	_label->setPixmap(QPixmap::fromImage(img)); // Show the image at the label in the plugin
}

void SamplePlugin::open(WorkCell* workcell)
{
    log().info() << "OPEN" << "\n";
    _wc = workcell;
    _state = _wc->getDefaultState();
	myViscServ = new VisualServoing(log().info(), _wc, _state);


    log().info() << workcell->getFilename() << "\n";

    if (_wc != NULL) {
        // Add the texture render to this workcell if there is a frame for texture
        Frame* textureFrame = _wc->findFrame("MarkerTexture");
        myMarker->setMarker(_wc);
        myMarker->setState(&_state);
        if (textureFrame != NULL) {
            getRobWorkStudio()->getWorkCellScene()->addRender("TextureImage",_textureRender,textureFrame);
        }


        // Add the background render to this workcell if there is a frame for texture
        Frame* bgFrame = _wc->findFrame("Background");
        if (bgFrame != NULL) {
            getRobWorkStudio()->getWorkCellScene()->addRender("BackgroundImage",_bgRender,bgFrame);
        }

        // Create a GLFrameGrabber if there is a camera frame with a Camera property set
        Frame* cameraFrame = _wc->findFrame("CameraSim");
        if (cameraFrame != NULL) {
            if (cameraFrame->getPropertyMap().has("Camera")) {
                // Read the dimensions and field of view
                double fovy;
                int width,height;
                std::string camParam = cameraFrame->getPropertyMap().get<std::string>("Camera");
                std::istringstream iss (camParam, std::istringstream::in);
                iss >> fovy >> width >> height;
                // Create a frame grabber
                _framegrabber = new GLFrameGrabber(width,height,fovy);
                SceneViewer::Ptr gldrawer = getRobWorkStudio()->getView()->getSceneViewer();
                _framegrabber->init(gldrawer);
            }
        }
    }

    // Load image
    Mat CvMarker = cv::imread(MARKER3);

    if (CvMarker.empty()) {
        log().info() << "Input image not found at '" << MARKER3 << "'\n";
        return;
    }

    // initialize vision part
    SURFObj.setMarker(CvMarker);
}


void SamplePlugin::close() {
    log().info() << "CLOSE" << "\n";

    // Stop the timer
    _timer->stop();
    // Remove the texture render
	Frame* textureFrame = _wc->findFrame("MarkerTexture");
	if (textureFrame != NULL) {
		getRobWorkStudio()->getWorkCellScene()->removeDrawable("TextureImage",textureFrame);
	}
	// Remove the background render
	Frame* bgFrame = _wc->findFrame("Background");
	if (bgFrame != NULL) {
		getRobWorkStudio()->getWorkCellScene()->removeDrawable("BackgroundImage",bgFrame);
	}
	// Delete the old framegrabber
	if (_framegrabber != NULL) {
		delete _framegrabber;
	}
	_framegrabber = NULL;
	_wc = NULL;
}

Mat SamplePlugin::toOpenCVImage(const Image& img) {
	Mat res(img.getHeight(),img.getWidth(), CV_8UC3);
	res.data = (uchar*)img.getImageData();
	return res;
}
Mat SamplePlugin::takePicture() {
    VelocityScrew6D<> imgPoints = myMarker->getMarkerPoints(POINTS);
    Frame* cameraFrame = _wc->findFrame("CameraSim");
    _framegrabber->grab(cameraFrame, _state);
    const Image& image = _framegrabber->getImage();

    // Convert to OpenCV image
    Mat im = toOpenCVImage(image);
    Mat imflip;
    cv::flip(im, imflip, 0);
    imflip.copyTo(im);
    cvtColor(im, im, CV_RGB2BGR);

    for(unsigned int i = 0;i <POINTS; i++){
        cv::circle(imflip,Point(imgPoints[i*2] + imflip.cols/2,imgPoints[i*2+1] + imflip.rows/2),5,Scalar(0,0,255),3);
        cv::circle(imflip,Point(TargetPoints[i*2] + imflip.cols/2,TargetPoints[i*2+1] + imflip.rows/2),8,Scalar(255,0,255),3);

        //log().info() << "changed" << imgPoints[i*2] + imflip.cols/2 << " " << imgPoints[i*2+1] + imflip.rows/2 << endl;

    }



    /*imshow("imflip: ", imflip);
    waitKey();*/
    // Show in QLabel
    QImage img(imflip.data, imflip.cols, imflip.rows, imflip.step, QImage::Format_RGB888);
    QPixmap p = QPixmap::fromImage(img);
    unsigned int maxW = 400;
    unsigned int maxH = 800;
    _label->setPixmap(p.scaled(maxW,maxH,Qt::KeepAspectRatio));

    // mark the targetpoints in green

    // mark the actual points in red

    return im;
}


void SamplePlugin::btnPressed() {
    QObject *obj = sender();
    VelocityScrew6D<> imgPoints = myMarker->getMarkerPoints(POINTS);
	if(obj==_btn0){
		log().info() << "Button 0\n";
		// Set a new texture (one pixel = 1 mm)
		Image::Ptr image;
        /*image = ImageLoader::Factory::load("/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/markers/Marker1.ppm");
		_textureRender->setImage(*image);*/

        myMarker->setImage(MARKER3);

        image = ImageLoader::Factory::load("/home/student/Desktop/7.semester/RoVi-finalProject/SamplePluginPA10/backgrounds/color2.ppm");
		_bgRender->setImage(*image);
		getRobWorkStudio()->updateAndRepaint();

        // get points from feachure extraction
        /*vector<Point2f> test = SURFObj.matchfeachures(takePicture());
        VelocityScrew6D<> imgPoints;
        for(int i = 0;i < 3; i++){
            imgPoints[i*2] = test[i].x;
            imgPoints[i*2+1] = test[i].y;
        }*/

        // calculate the image jacobian
        myViscServ->setImageJacobian(FOCALLENGTH, Z_COORDINAT, imgPoints);
        TargetPoints = imgPoints;
        takePicture();

	} else if(obj==_btn1){

        /*Q next = myViscServ->nextQ(imgPoints, DELTA_T);
        log().info() << "Q: " << next << endl;
        // setup devise

        Device::Ptr device;
        device = _wc->findDevice("PA10");

        if (device == NULL) {
            log().info() << "read of device failed\n";
        }

        device->setQ(next, _state);
        getRobWorkStudio()->setState(_state);
*/
        /*if (_framegrabber != NULL) {
            // get points from feachure extraction
            vector<Point2f> test = SURFObj.matchfeachures(takePicture());
            log().info() << " Looking for marker ->";

            if(test.size() == 4) {
                log().info() << " marker found: \n";
                VelocityScrew6D<> imgPoints;
                for (int i = 0; i < 3; i++) {
                    imgPoints[i * 2] = test[i].x;
                    imgPoints[i * 2 + 1] = test[i].y;
                }

                // mover the marker
                //myMarker->moveMarker();
                Transform3D<> FramePose = myMarker->getPosition();
                VelocityScrew6D<> dU(FramePose);



            }

        }*/


		log().info() << "Button 1\n";
		// Toggle the timer on and offs
        if (!_markerMover->isActive())
            _markerMover->start(DELTA_T); // run 10 Hz
        else
            _markerMover->stop();

        if (!_timer->isActive())
            _timer->start(DELTA_T); // run 10 Hz
		else
			_timer->stop();
	} else if(obj==_spinBox){
		log().info() << "spin value:" << _spinBox->value() << "\n";
	}
}

void SamplePlugin::timer() {
	if (_framegrabber != NULL) {
		// Get the image as a RW image
		takePicture();
        VelocityScrew6D<> imgPoints = myMarker->getMarkerPoints(POINTS);
        Q next = myViscServ->nextQ(imgPoints, DELTA_T);
        log().info() << "Q: " << next << endl;
        // setup devise

        Device::Ptr device;
        device = _wc->findDevice("PA10");

        if (device == NULL) {
            log().info() << "read of device failed\n";
        }

        device->setQ(next, _state);
        getRobWorkStudio()->setState(_state);
	}


}

void SamplePlugin::markerTimer(){


    //log().info() << myMarker->getPosition().P() << endl;
}

void SamplePlugin::stateChangedListener(const State& state) {
  _state = state;
}
