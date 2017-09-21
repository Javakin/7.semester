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
    cv::waitKey();





    // save the images

    return 0;
}


//function definition
void rect1(){
    //rectangle drawn using rectangle draw funciton
    cv::Mat img = cv::imread("../color.png");

    cv::Point p1= cv::Point(350,100);
    cv::Point p2= Point(440,220);

    rectangle( img, p1, p2, Scalar( 0, 0, 0 ), -1, 8 );

    cv::imshow("ImageRect1",img);
    cv::waitKey();

}


void rect2(){
    // rectangle drawn using line draw function
    cv::Mat img = cv::imread("../color.png");
    Point start, end;
    cv::Point p1= cv::Point(350,100);
    cv::Point p2= Point(440,220);

    start = p1;
    end = p2;
    int thickness = 0;
    int lineType = 8;

    for (unsigned int i = 100; i<=220; i++ ){
        start.y = i;
        end.y = i;
        line( img, start, end, Scalar( 0, 0, 0 ),
              thickness,
              lineType );
    }


        cv::imshow("ImageRect2",img);
        cv::waitKey();
}


void rect3(){
    // rectangle drawn using point manipulation functions
    cv::Mat img = cv::imread("../color.png");
    cv::Point p1= cv::Point(350,100);
    cv::Point p2= Point(440,220);


    for (unsigned int i = 350; i<=440; i++){
        for(unsigned int j = 100; j<=220; j++){
            Vec3b &color = img.at<Vec3b>(Point(i,j));
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
        }
    }

    // save the image in a file
    cv::imwrite("../Images/rect3.png",img);
    cv::imshow("ImageRect3",img);
    cv::waitKey();


}

void rectColor(){
    // todo
    cv::Mat img = cv::imread("../color.png");

    cv::Point p1= cv::Point(350,100);
    cv::Point p2= Point(440,220);

    rectangle( img, p1, p2, Scalar( 0, 255, 0 ), -1, 8 );

    cv::imshow("ImageRectCol",img);
    cv::waitKey();

}













