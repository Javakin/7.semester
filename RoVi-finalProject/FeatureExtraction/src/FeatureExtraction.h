//
// Created by student on 12/10/17.
//

#ifndef FEATUREEXTRACTION_FEATUREEXTRACTION_H
#define FEATUREEXTRACTION_FEATUREEXTRACTION_H

#include "opencv2/xfeatures2d.hpp"
#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;

class FeatureExtraction {
public:
    FeatureExtraction();
    FeatureExtraction(int iHassanThreshhold);

    // generate the feachures
    void setMarker(Mat mMarker);
    void matchfeachures(Mat mImage);

private:
    Ptr<SURF> detector;
    std::vector<KeyPoint> vKeyPointsMarker;
    Mat mDescriptorsMaker;
    Mat mMarker;
};


#endif //FEATUREEXTRACTION_FEATUREEXTRACTION_H
