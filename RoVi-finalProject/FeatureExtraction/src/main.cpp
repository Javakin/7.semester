/*
 * RoVi1
 * Example application to load and display an image
 */

// v1.0-4-gdfe246a

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Markers.h"

#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

using namespace cv::xfeatures2d;

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

    // extract the feachures of the marker using the example of source:
    // https://docs.opencv.org/master/d5/d6f/tutorial_feature_flann_matcher.html
    Mat img_1; Mat img_2;
    NewMarker.getReference(img_1, MARKER3);
    NewMarker.getMarker(img_2, MARKER3, EASY, 1);

    //-- Step 1: Detect the keypoints using SURF Detector, compute the descriptors
    int minHessian = 400;
    Ptr<SURF> detector = SURF::create();
    detector->setHessianThreshold(minHessian);
    std::vector<KeyPoint> keypoints_1, keypoints_2;
    Mat descriptors_1, descriptors_2;
    detector->detectAndCompute( img_1, Mat(), keypoints_1, descriptors_1 );
    detector->detectAndCompute( img_2, Mat(), keypoints_2, descriptors_2 );

    //-- Step 2: Matching descriptor vectors using FLANN matcher
    FlannBasedMatcher matcher;
    std::vector< DMatch > matches;
    matcher.match( descriptors_1, descriptors_2, matches );

    // draw matches
    Mat img_matches5;
    drawMatches( img_1, keypoints_1, img_2, keypoints_2, matches, img_matches5 );
    imshow("All matches", img_matches5);
    cv::waitKey();


    double max_dist = 0; double min_dist = 100;
    //-- Quick calculation of max and min distances between keypoints
    for( int i = 0; i < descriptors_1.rows; i++ )
    { double dist = matches[i].distance;
        if( dist < min_dist ) min_dist = dist;
        if( dist > max_dist ) max_dist = dist;
    }
    printf("-- Max dist : %f \n", max_dist );
    printf("-- Min dist : %f \n", min_dist );
    //-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
    //-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
    //-- small)
    //-- PS.- radiusMatch can also be used here.
    std::vector< DMatch > good_matches;
    for( int i = 0; i < descriptors_1.rows; i++ )
    { if( matches[i].distance <= max(2*min_dist, 0.02) )
        { good_matches.push_back( matches[i]); }
    }
    //-- Draw only "good" matches
    Mat img_matches;
    drawMatches( img_1, keypoints_1, img_2, keypoints_2,
                 good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
                 vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
    //-- Show detected matches
    imshow( "Good Matches", img_matches );
    for( int i = 0; i < (int)good_matches.size(); i++ )
    { printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx ); }
    waitKey(0);

    // extract the feachures of the image marker
    Mat keypoints;
    cv::drawKeypoints(img_1, keypoints_1,keypoints,  Scalar::all(-1), 4);
    cv::imshow("keypoints", keypoints);
    cv::waitKey();

    return 0;
}
