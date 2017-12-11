/*
 * RoVi1
 * Example application to load and display an image
 */

// v1.0-4-gdfe246a

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Markers.h"
#include "FeatureExtraction.h"



using namespace cv;
using namespace std;



int main()
{
    Markers NewMarker;

    // Get the marker
    Mat Marker;
    NewMarker.getReference(Marker, MARKER3);

    // Show the image
    cv::imshow("Marker3", Marker);
    cv::waitKey();


    //Finde the marker in all images
    Mat img;
    FeatureExtraction SURFObj(400);     // setup the feachure extraciton class
    SURFObj.setMarker(Marker);

    for(int i = 1; i<=52; i++) {
        NewMarker.getMarker(img, MARKER3, HARD, i);

        vector<Point2f> test = SURFObj.matchfeachures(img);

        // Show the image
        /*cv::imshow("Image" + to_string(i), img);
        cv::waitKey();*/
    }


    return 0;
}
