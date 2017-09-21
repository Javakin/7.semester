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
    lenaGray50 = lenaGray.clone();
    vIntensityTransform(lenaGray50, 50);

    // 2. Histogram calculation

    // calculate the histogram of the function
    Mat gray_hist, gray50_hist;
    int histSize=256;
    float range[] = { 0, 256 };
    const float* histRange = { range };

    calcHist(&lenaGray, 1, 0, Mat(), gray_hist, 1, &histSize, &histRange, true, false );
    calcHist(&lenaGray50, 1, 0, Mat(), gray50_hist, 1, &histSize, &histRange, true, false );

    //normalize the histogram


    // plot the histogra
    int N = 100;
    Mat plotHist = Mat::zeros(N,256,CV_8U);


    // locate the max histogram value
    double min, max;
    cv::minMaxLoc(gray_hist, &min, &max);

    cv::waitKey();

    double H = 0;
    for(unsigned int i = 0; i <256;i++){

        H = N*(gray_hist.at<float>(i))/(max);


        line(plotHist, Point(i, N-1), Point(i, N-(int)H),Scalar(255,255,255),1,8,0 );
    }

    cout << gray_hist.at<double>(0,0) << endl;
    cout << gray_hist.rows << " " << gray_hist.cols << endl;


    imwrite("../Exercise_2/image/Histogram.png",plotHist);
    cv::imshow("Image", plotHist);
    cv::waitKey();

    // 3. Linear filtering

    // Show the image
    cv::imshow("Image", lenaGray);
    cv::waitKey();

    return 0;
}

 void vIntensityTransform(Mat & anImg, int alpha){
    // increment the intensity by alpha of each pixel
    for(unsigned int i = 0; i<anImg.size().width; i++ ){
        for(unsigned int j = 0; j<anImg.size().height; j++ ){
            if(anImg.at<uchar>(i, j)<256-alpha)
                anImg.at<uchar>(i, j) = anImg.at<uchar>(i, j) +alpha;
            else
                anImg.at<uchar>(i,j) = 255;
        }
    }

 }








