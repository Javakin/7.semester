//
// Created by student on 12/10/17.
//

#include "FeatureExtraction.h"


FeatureExtraction::FeatureExtraction() {

    // Constrct the SURF detector
    int minHessian = 400;
    detector = SURF::create();
    detector->setHessianThreshold(minHessian);
}

FeatureExtraction::FeatureExtraction(int iHassanThreshhold) {

    // Constrct the SURF detector
    detector = SURF::create();
    detector->setHessianThreshold(iHassanThreshhold);
}

void FeatureExtraction::setMarker(Mat aMarker) {
    detector->detectAndCompute( aMarker, Mat(), vKeyPointsMarker, mDescriptorsMaker);
    aMarker.copyTo(mMarker);
}

void FeatureExtraction::matchfeachures(Mat mImage) {
    // solution based on source: https://docs.opencv.org/master/d5/d6f/tutorial_feature_flann_matcher.html

    //-- Setep 1 set up descriptors and keypoints for the target image
    vector<KeyPoint> vKeyPointImage;
    Mat mDescriptorImage;
    detector->detectAndCompute( mImage, Mat(), vKeyPointImage, mDescriptorImage);

    //-- Step 2: Matching descriptor vectors using FLANN matcher
    FlannBasedMatcher matcher;
    std::vector< DMatch > matches;
    matcher.match( mDescriptorsMaker, mDescriptorImage, matches );


    // draw matches - for debugging
    /*Mat img_matches5;
    drawMatches( mMarker, vKeyPointsMarker, mImage, vKeyPointImage, matches, img_matches5 );
    imshow("All matches", img_matches5);
    cv::waitKey();*/


    double max_dist = 0; double min_dist = 100;
    //-- Quick calculation of max and min distances between keypoints
    for( int i = 0; i < mDescriptorsMaker.rows; i++ )
    {
        double dist = matches[i].distance;
        if( dist < min_dist ) min_dist = dist;
        if( dist > max_dist ) max_dist = dist;
    }
    /*printf("-- Max dist : %f \n", max_dist );
    printf("-- Min dist : %f \n", min_dist );*/
    //-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
    //-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
    //-- small)
    //-- PS.- radiusMatch can also be used here.
    std::vector< DMatch > good_matches;
    for( int i = 0; i < mDescriptorsMaker.rows; i++ )
    { if( matches[i].distance <= max(2*min_dist, 0.02) )
        { good_matches.push_back( matches[i]); }
    }


    //-- Draw only "good" matches
    Mat img_matches;
    drawMatches( mMarker, vKeyPointsMarker, mImage, vKeyPointImage,
                 good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
                 vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );


    //-- Show detected matches
    imshow( "Good Matches", img_matches );
    waitKey(10);

    /*for( int i = 0; i < (int)good_matches.size(); i++ )
    { printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx ); }
*/

    // use the good matches to finde the homography



}
