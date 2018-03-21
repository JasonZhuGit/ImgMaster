#include "viewpanel.h"

ViewPanel::ViewPanel(QWidget *parent) : QWidget(parent)
{
    this->setupUi(parent);
}

ViewPanel::~ViewPanel()
{
}

void ViewPanel::setupUi(QWidget * parent)
{
    pMainLayout = new QGridLayout();
//  pMainLayout->setSpacing(0);
    pMainLayout->setMargin(0);
    pImgView = new ImageView(parent, ScrollView);
    pMainLayout->addWidget(pImgView);
    this->setLayout(pMainLayout);
//    pImgView->setFocus();
}

void ViewPanel::showImage(const cv::Mat &image)
{
    pImgView->showImage(image);
}
