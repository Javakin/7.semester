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

    // Display all the markers
    /*
    for(int i = 1; i<=52; i++) {
        NewMarker.getMarker(img, MARKER3, HARD, i);

        // Show the image
        cv::imshow("Image" + to_string(i), img);
        cv::waitKey();
    }*/

    // Get the marker true marker
    Mat Marker;
    NewMarker.getReference(Marker, MARKER3);

    // Show the image
    cv::imshow("Marker3", Marker);
    cv::waitKey();

    // extract the feachures of the marker


    // extract the feachures of the image marker

    return 0;
}
