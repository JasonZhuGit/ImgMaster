#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QImage>
#include <QPixmap>
#include <QDebug>


enum view_type{
    ScrollView = 0,
    ScaleView = 1
};

class ImageView : public QScrollArea
{
public:
    explicit ImageView(QWidget *parent = 0, view_type vType=ScrollView);
    view_type type;
    QLabel * imgLabel;

    //cv::Mat img;    //image to be showed
    void setupUi();

    void focusInEvent(QFocusEvent * event);
    void focusOutEvent(QFocusEvent * event);
    void paintEvent(QPaintEvent * event);


public:
    //void setImg(cv::Mat mat);
    //cv::Mat getImg();
    void showImage(const cv::Mat & img);

};

#endif // IMAGEVIEW_H
