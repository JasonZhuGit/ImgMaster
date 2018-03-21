#include "filelistdockwidget.h"

FileListDockWidget::FileListDockWidget(QWidget *parent) : QDockWidget(parent)
{
    setupUi();
    initConnect();
}

void FileListDockWidget::setupUi()
{
    pFileList = new QListWidget(this);
    pMainLayout = new QGridLayout();
    pMainLayout->addWidget(pFileList);
    pMainLayout->setSpacing(0);
    pMainLayout->setMargin(5);
    pBaseWidget = new QWidget(this);
    pBaseWidget->setLayout(pMainLayout);
    this->setWidget(pBaseWidget);
    this->setMaximumWidth(200);
    this->setMinimumWidth(100);
}

void FileListDockWidget::addImageList(std::vector<string> strlist)
{
    std::vector<string>::iterator it = strlist.begin();
    std::vector<string>::iterator itEnd = strlist.end();
    pFileList->clear();
    while (it != itEnd){
        pFileList->addItem(QString::fromStdString(*it));
        it++;
    }
}

void FileListDockWidget::selectBackImage()
{
    setSelectImage(pFileList->count() - 1);
}

void FileListDockWidget::setSelectImage(int index)
{
    pFileList->setCurrentRow(index);
    pFileList->setFocus();
}

void FileListDockWidget::initConnect()
{
    connect(pFileList, &QListWidget::itemClicked, this, &FileListDockWidget::on_list_item_clicked);
}

void FileListDockWidget::on_list_item_clicked(QListWidgetItem * item)
{
    //qDebug() << "item: " << item;
    //qDebug() << "index: " << pFileList->currentRow();
    Q_UNUSED(item)
    emit switchImageSignal(pFileList->currentRow());
}
