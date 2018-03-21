#include "viewpanelsholder.h"

ViewPanelsHolder::ViewPanelsHolder(QWidget *parent) : QStackedWidget(parent)
{
    curIndex = 0;
    setupUi();
}

ViewPanelsHolder::~ViewPanelsHolder()
{

}

void ViewPanelsHolder::setupUi()
{
    this->setFrameStyle(QFrame::StyledPanel);
    //this->setMaximumWidth(200);
    //this->setMinimumWidth(200);
    //this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
    pMultiViewPanel = new MultiViewPanel(this);
    this->addWidget(pMultiViewPanel);
    this->setCurrentIndex(curIndex);
}

void ViewPanelsHolder::showImages(CoreImage * pCoreImage)
{
    pMultiViewPanel->showImages(pCoreImage);
}
