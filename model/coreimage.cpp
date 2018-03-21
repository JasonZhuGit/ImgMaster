#include "coreimage.h"

CoreImage::CoreImage()
{
    title = "untitled";
    ext = ".bmp";
    path = "./";
    bInPlace = false;
}

CoreImage::~CoreImage()
{

}

void CoreImage::setTitle(const string & title)
{
    this->title = title;
}

string CoreImage::getTitle()
{
    return title;
}

void CoreImage::splitFullPathname(const string & fullPathname)
{
    path = fullPathname.substr(0, fullPathname.find_last_of('/'));
    string name = fullPathname.substr(fullPathname.find_last_of('/') + 1);
    title = name.substr(0, name.find_last_of('.'));
    ext = name.substr(name.find_last_of('.'));
    std::cout << path << std::endl;
    std::cout << title << std::endl;
    std::cout << ext << std::endl;
}

string CoreImage::splitTitle(const string & str)
{
    //int pos = str.find_last_of('/');
    //string subname = str.substr(pos+1);
    //int pos2 = subname.find_first_of('.');
    //std::cout << "title: " << subname.substr(0, pos2) << std::endl;
    //return subname.substr(0, pos2);
    return str.substr(str.find_last_of('/') + 1, str.find_last_of('.')-str.find_last_of('/') - 1);
}

bool CoreImage::loadImage(const string &filename)
{
    //setTitle(splitTitle(filename));
    splitFullPathname(filename);
    imageMat = cv::imread(filename);
    if (imageMat.data)
        return true;
    else
        return false;
}

cv::Mat CoreImage::getImageMat()
{
    return imageMat;
}

void CoreImage::SetImageMat(const Mat &imgMat)
{
    imageMat.create(imgMat.rows, imgMat.cols, imgMat.type());
    imageMat = imgMat.clone();
}

cv::Mat CoreImage::getRedChannel(bool bColor)
{
    if (imageMat.channels() == 3)
    {
        if (bColor)
        {
            cv::Mat colorMat(imageMat.rows, imageMat.cols, CV_8UC3);
            cv::Mat_<cv::Vec3b>::iterator it = imageMat.begin<cv::Vec3b>();
            cv::Mat_<cv::Vec3b>::iterator itEnd = imageMat.end<cv::Vec3b>();
            cv::Mat_<cv::Vec3b>::iterator colorIt = colorMat.begin<cv::Vec3b>();
            for(it; it != itEnd; it++, colorIt++)
            {
                (*colorIt)[0] = 0;
                (*colorIt)[1] = 0;
                (*colorIt)[2] = (*it)[2];
            }
            return colorMat;
        }
        else
        {
            std::vector<cv::Mat> BGRChannels;
            cv::split(imageMat, BGRChannels);
            return BGRChannels[2];
        }
    }
    else
        return imageMat;
}

cv::Mat CoreImage::getGreenChannel(bool bColor)
{
    if (imageMat.channels() == 3)
    {
        if (bColor)
        {
            cv::Mat colorMat(imageMat.rows, imageMat.cols, CV_8UC3);
            cv::Mat_<cv::Vec3b>::iterator it = imageMat.begin<cv::Vec3b>();
            cv::Mat_<cv::Vec3b>::iterator itEnd = imageMat.end<cv::Vec3b>();
            cv::Mat_<cv::Vec3b>::iterator colorIt = colorMat.begin<cv::Vec3b>();
            for(it; it != itEnd; it++, colorIt++)
            {
                (*colorIt)[0] = 0;
                (*colorIt)[1] = (*it)[1];
                (*colorIt)[2] = 0;
            }
            return colorMat;
        }
        else
        {
            std::vector<cv::Mat> BGRChannels;
            cv::split(imageMat, BGRChannels);
            return BGRChannels[1];
        }
    }
    else
        return imageMat;
}

cv::Mat CoreImage::getBlueChannel(bool bColor)
{
    if (imageMat.channels() == 3)
    {
        if (bColor)
        {
            cv::Mat colorMat(imageMat.rows, imageMat.cols, CV_8UC3);
            cv::Mat_<cv::Vec3b>::iterator it = imageMat.begin<cv::Vec3b>();
            cv::Mat_<cv::Vec3b>::iterator itEnd = imageMat.end<cv::Vec3b>();
            cv::Mat_<cv::Vec3b>::iterator colorIt = colorMat.begin<cv::Vec3b>();
            for(it; it != itEnd; it++, colorIt++)
            {
                (*colorIt)[0] = (*it)[0];
                (*colorIt)[1] = 0;
                (*colorIt)[2] = 0;
            }
            return colorMat;
        }
        else
        {
            std::vector<cv::Mat> BGRChannels;
            cv::split(imageMat, BGRChannels);
            return BGRChannels[0];
        }
    }
    else
        return imageMat;
}
