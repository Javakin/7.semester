/*
 * RoVi1
 * Exercise 1 - Draw different types of rechtangles
 * date: 18-sep-17
 */

// v1.0-4-gdfe246a

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


// function declaration
void rect1();
void rect2();
void rect3();
void rectColor();
void grayScale();


// Main program
int main()
{
    // Load image
    cv::Mat img = cv::imread("../color.png");

    // chek for errors
    if (img.empty()) {
        return 1;
    }

    // 1. different methods for drawing black rectangles
    rect1();
    rect2();
    rect3();

    // 2. draw a collered rectangle
    rectColor();


    // 3. comvert the image to grayscale
    cv::Mat graySC = cv::imread("../color.png", CV_LOAD_IMAGE_GRAYSCALE);

        // display image
    cv::imshow("Image", graySC);
   // cv::waitKey();





    // save the images

    return 0;
}


//function definition
void rect1(){
    //rectangle drawn using rectangle draw funciton
}


void rect2(){
    // rectangle drawn using line draw function

}


void rect3(){
    // rectangle drawn using point manipulation functions
    cv::Mat img = cv::imread("../color.png");
    cv::Mat img2 = img.clone();


    for (unsigned int i = 7; i<=70; i++){
        for(unsigned int j = 8; j<=80; j++){
            cout << i << j<< endl;
            //img.at<cv::Vec3b>(i, j) = cv::Scalar::all(0);
        }
    }
    Vec3b intensity = img.at<Vec3b>(10, 10);
    uchar blue = intensity.val[0];
    uchar green = intensity.val[1];
    uchar red = intensity.val[2];

    cout << "blue" << (int)blue << " green" << (int)green << " red" << (int)red << endl;

    // save the image in a file
    cv::imwrite("../Images/rect3.png",img2);
    cv::imshow("Image58",img);
    cv::waitKey();


}

void rectColor(){
    // todo

}













