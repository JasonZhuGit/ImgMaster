#include "baseinfopanel.h"

BaseInfoPanel::BaseInfoPanel(QWidget *parent) : QWidget(parent)
{
    this->setupUi();
    this->initConnect();
}

void BaseInfoPanel::setupUi()
{
    pImgList = new QListWidget(this);
    pImgList->setViewMode(QListView::ListMode);
    pMainLayout = new QGridLayout();
    pMainLayout->setMargin(0);
    pMainLayout->setSpacing(4);
    pMainLayout->addWidget(pImgList);
    this->setLayout(pMainLayout);
}

void BaseInfoPanel::addImageList(std::vector<string> strlist)
{
    std::vector<string>::iterator it = strlist.begin();
    std::vector<string>::iterator itEnd = strlist.end();
    pImgList->clear();
    while (it != itEnd){
        pImgList->addItem(QString::fromStdString(*it));
        it++;
    }
}

void BaseInfoPanel::selectBackImage()
{
    setSelectImage(pImgList->count() - 1);
}

void BaseInfoPanel::setSelectImage(int index)
{
    pImgList->setCurrentRow(index);
    pImgList->setFocus();
}

void BaseInfoPanel::initConnect()
{
    connect(pImgList, &QListWidget::itemClicked, this, &BaseInfoPanel::on_list_item_clicked);
}

void BaseInfoPanel::on_list_item_clicked(QListWidgetItem * item)
{
    //qDebug() << "item: " << item;
    //qDebug() << "index: " << pImgList->currentRow();
    emit switchImageSignal(pImgList->currentRow());
}

void BaseInfoPanel::showImageChannels(cv::Mat &img)
{
    int channels = img.channels();
    std::vector<cv::Mat> planes;
    if(channels == 3 || channels == 4)
    {
        cv::split(img, planes);
    }
    else
    {
        planes.push_back(img);
        planes.push_back(img);
        planes.push_back(img);
    }
    redChannel->showImg(planes[2]);
    greenChannel->showImg(planes[1]);
    blueChannel->showImg(planes[0]);
}
