/*
 * RoVi1
 * Example application to load and display an image
 */


// v1.0-4-gdfe246a

// ------------------------------------  includes ------------------------------------
#include <opencv2/opencv.hpp>
#include <iostream>

// ------------------------------------  namespaces ------------------------------------
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

     cout << "Rows: " << anImg.at<Vec3b>(10,10) << endl;

    namedWindow("Display Example 1", 1);
    namedWindow("Original Image", 1 );

    imshow("Display Example 1", anImg);
    imshow("Origunal Image", imread("../Exercise_2/lena.bmp"));

    waitKey();

 }








