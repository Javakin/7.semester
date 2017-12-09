/*
 * RoVi1
 * Example application to load and display an image
 */

// v1.0-4-gdfe246a

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Markers.h"

using namespace cv;
using namespace std;

int main()
{
    Mat img;
    Markers NewMarker;

    // display all the markers at a given location
    for(int i = 1; i<=52; i++) {
        NewMarker.gitMarker(img, MARKER3, HARD, i);

        // Show the image
        cv::imshow("Image" + to_string(i), img);
        cv::waitKey();
    }

    return 0;
}
