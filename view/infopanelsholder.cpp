#include "infopanelsholder.h"

InfoPanelsHolder::InfoPanelsHolder(QWidget *parent) : QStackedWidget(parent)
{
    curIndex = 0;
    this->pParent = parent;
    setupUi();
}


void InfoPanelsHolder::setupUi()
{
    //this->setFrameStyle(QFrame::NoFrame);
    this->setFrameStyle(QFrame::StyledPanel);
    this->setMaximumWidth(180);
    this->setMinimumWidth(180);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
    pImageListPanel = new ImageListPanel(this);
    this->addWidget(pImageListPanel);
    this->setCurrentIndex(curIndex);
}

void InfoPanelsHolder::updateImageListItem(QVector<QString> strlist)
{
    pImageListPanel->setImageList(strlist);
}

int InfoPanelsHolder::getImagesCount()
{
    return pImageListPanel->pImageList->count();
}

void InfoPanelsHolder::selectImageListItem(int index)
{
    pImageListPanel->selectImageListItem(index);
}
