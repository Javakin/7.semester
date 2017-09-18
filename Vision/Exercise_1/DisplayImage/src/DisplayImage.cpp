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
    Mat img2 = clone(img);
    rect1();
    rect2();
    rect3();

    // 2. draw a collered rectangle
    rectColor();

    // 3. comvert the image to grayscale
    grayScale();

    // Show the images
    cv::imshow("Image", img2);
    cv::waitKey();

    // save the images

    return 0;
}


//function definition
void rect1(){
    cout << "stuff - tjis is function 1" << endl;
}


void rect2(){
    cout << "stuff - tjis is function 2" << endl;
}


void rect3(){
    cout << "stuff - this is function 3" << endl;
}

void rectColor(){

}

void grayScale(){

}











