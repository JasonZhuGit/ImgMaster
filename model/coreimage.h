#ifndef COREIMAGE_H
#define COREIMAGE_H

#include <string>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class CoreImage
{
public:
    CoreImage();
    ~CoreImage();

    cv::Mat imageMat;
    std::vector<cv::Mat> channelLayers;
    cv::Mat histograms;
    string title;
    string ext;
    string path;
    bool bInPlace;

    void setTitle(const string &title);
    string getTitle();
    bool loadImage(const string & filename);
    cv::Mat getImageMat();
    void SetImageMat(const cv::Mat & imgMat);
    cv::Mat getRedChannel(bool bColor=false);
    cv::Mat getGreenChannel(bool bColor=false);
    cv::Mat getBlueChannel(bool bColor=false);
    string splitTitle(const string & str);
    void splitFullPathname(const string & fullPathname);
};

#endif // COREIMAGE_H
