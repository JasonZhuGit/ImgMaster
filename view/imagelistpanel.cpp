#include "imagelistpanel.h"

ImageListPanel::ImageListPanel(QWidget *parent) : QWidget(parent)
{
    this->setupUi();
    this->initConnect();
}

void ImageListPanel::setupUi()
{
    pImageList = new QListWidget(this);
    pImageList->setViewMode(QListView::ListMode);
    pMainLayout = new QGridLayout();
    pMainLayout->setMargin(5);
    pMainLayout->setSpacing(5);
    pMainLayout->addWidget(pImageList);
    this->setLayout(pMainLayout);
}

void ImageListPanel::initConnect()
{
    connect(pImageList, &QListWidget::itemClicked, this, &ImageListPanel::onItemClicked);
}

void ImageListPanel::setImageList(QVector<QString> strlist)
{
    QVector<QString>::iterator iter;
    pImageList->clear();
    for(iter = strlist.begin(); iter != strlist.end(); iter++)
    {
        pImageList->addItem(*iter);
    }
}

void ImageListPanel::selectImageListItem(int index)
{
    pImageList->setCurrentRow(index);
    pImageList->setFocus();
}

void ImageListPanel::onItemClicked(QListWidgetItem * item)
{
    Q_UNUSED(item);
    emit signalShowImage(pImageList->currentRow());
}
