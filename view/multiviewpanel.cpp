#include "multiviewpanel.h"

MultiViewPanel::MultiViewPanel(QWidget *parent) : QWidget(parent)
{
    this->setupUi();
}

MultiViewPanel::~MultiViewPanel()
{

}

void MultiViewPanel::setupUi()
{
    redView = new ImageView(this, ScaleView);
    greenView = new ImageView(this, ScaleView);
    blueView = new ImageView(this, ScaleView);
    histView = new ImageView(this, ScaleView);
    partWidget = new QWidget(this);
    partLayout = new QVBoxLayout();
    partLayout->setMargin(0);
    partLayout->setSpacing(5);
    partLayout->addWidget(redView);
    partLayout->addWidget(greenView);
    partLayout->addWidget(blueView);
    partLayout->addWidget(histView);
    partWidget->setLayout(partLayout);
    partWidget->setMaximumWidth(240);
    partWidget->setMinimumWidth(240);
    mainView = new ImageView(this, ScrollView);
    mainLayout = new QHBoxLayout();
    mainLayout->addWidget(partWidget);
    mainLayout->addWidget(mainView);
    mainLayout->setMargin(5);
    this->setLayout(mainLayout);
}

void MultiViewPanel::showImages(CoreImage * pCoreImage)
{
    mainView->showImage(pCoreImage->getImageMat());
    redView->showImage(pCoreImage->getRedChannel(true));
    greenView->showImage(pCoreImage->getGreenChannel(true));
    blueView->showImage(pCoreImage->getBlueChannel(true));
    histView->showImage(pCoreImage->getImageMat());
}
