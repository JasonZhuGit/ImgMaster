#ifndef VIEWPANEL_H
#define VIEWPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <view/imageview.h>
#include <opencv2/core/core.hpp>

class ViewPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ViewPanel(QWidget *parent = 0);
    ~ViewPanel();
    ImageView * pImgView;
    QGridLayout * pMainLayout;

    void setupUi(QWidget * parent);

    void showImage(const cv::Mat & image);
signals:

public slots:
};

#endif // VIEWPANEL_H
