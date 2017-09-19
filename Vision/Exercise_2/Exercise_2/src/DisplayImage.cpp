/*
 * RoVi1
 * Example application to load and display an image
 */
using namespace std;
using namespace cv;

// ------------------------------------ function declarations ------------------------------------
 void vIntensityTransform(Mat & anImg, int alpha);

int main(int argc, char* argv[])
{

    // Parse command line arguments
    cv::CommandLineParser parser(argc, argv,
        "{help   |            | print this message}"
        "{@image | ./book.jpg | image path}"
    );


    // v1.0-4-gdfe246a

    // ------------------------------------  includes ------------------------------------
    #include <opencv2/opencv.hpp>
    #include <iostream>

    // ------------------------------------  namespaces ------------------------------------
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    // Load image
    std::string filename = parser.get<std::string>("@image");
    cv::Mat lenaGray = cv::imread(filename,0);

    if (lenaGray.empty()) {
        std::cout << "Input image not found at '" << filename << "'\n";
        return 1;
    }

    // 1. IntensityTransform the matrix
    vIntensityTransform(lenaGray, 50);

    // 2. Histogram calculation

    // 3. Linear filtering



    // Show the image
    cv::imshow("Image", lenaGray);
    cv::waitKey();

    return 0;
}

 void vIntensityTransform(Mat & anImg, int alpha){
    // increment the intensity by alpha of each pixel

    //for(unsigned int i = anImg.rows(); i )

     for (unsigned int i = 350; i<=440; i++){
         for(unsigned int j = 100; j<=220; j++){
             Vec3b &color = img.at<Vec3b>(Point(i,j));
             color[0] = 0;
             color[1] = 0;
             color[2] = 0;
         }
     }

     cout << "Width : " << anImg.size().width << endl;
     cout << "Height: " << anImg.size().height << endl;



    waitKey();

 }








