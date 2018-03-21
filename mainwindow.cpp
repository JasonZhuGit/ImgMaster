#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    curSelectedIndex = 0;
    setupUi();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUi()
{
    initWidgets();
    initAction();
    initMenuBar();
    initToolBar();
    initConnect();
}

void MainWindow::initWidgets()
{
    this->resize(800, 600);
    this->setWindowState(Qt::WindowMaximized);
    std::cout << "in";
    pCentralWidget = new QWidget(this);
    pMainLayout = new QHBoxLayout();
    pInfoPanelsHolder = new InfoPanelsHolder(this);
    pViewPanelsHolder = new ViewPanelsHolder(this);
    pProcPanelsHolder = new ProcPanelsHolder(this);
    pMainLayout->addWidget(pInfoPanelsHolder);
    pMainLayout->addWidget(pViewPanelsHolder);
    pMainLayout->addWidget(pProcPanelsHolder);
    pMainLayout->setMargin(10);
    pCentralWidget->setLayout(pMainLayout);
    this->setCentralWidget(pCentralWidget);
}

void MainWindow::initAction()
{
    fileOpenAction = new QAction(QIcon(":/icon/fileOpen"), QString("&Open..."), this);
//    fileOpenAction->setShortcut(QKeySequence::Open);//shortcut
    fileOpenAction->setStatusTip(QString("Open an exits file"));
    fileSaveAction = new QAction(QIcon(":/icon/fileSave"), QString("&Save File"), this);
    fileSaveAction->setStatusTip(QString("Save current files"));

}

void MainWindow::initMenuBar()
{
    pMainMenuBar = new QMenuBar(this);
    pMainMenuBar->setGeometry(QRect(0, 0, 1366, 230));
    this->setMenuBar(pMainMenuBar);
    pFileMenu = new QMenu(QString("&File"), pMainMenuBar);
    pFileMenu->addAction(fileOpenAction);
    pFileMenu->addAction(fileSaveAction);
    pMainMenuBar->addMenu(pFileMenu);
    pPanelsMenu = new QMenu(QString("&Panel"), pMainMenuBar);
    pMainMenuBar->addMenu(pPanelsMenu);
}

void MainWindow::initToolBar()
{
    pFileToolBar = new QToolBar(this);
    pPanelsToolBar = new QToolBar(this);
    QSize iconSize(30, 30);
    pFileToolBar->setIconSize(iconSize);
    pFileToolBar->addAction(fileOpenAction);
    pFileToolBar->addAction(fileSaveAction);
    pPanelsToolBar->setIconSize(iconSize);
    this->addToolBar(Qt::TopToolBarArea, pFileToolBar);
    this->addToolBar(Qt::TopToolBarArea, pPanelsToolBar);
}

void MainWindow::initConnect()
{
    connect(fileOpenAction, &QAction::triggered, this, &MainWindow::slotFileOpen);
    connect(pProcPanelsHolder->pBasePanel, &BaseProcPanel::file_open_signal, this, &MainWindow::slotFileOpen);
    connect(pInfoPanelsHolder->pImageListPanel, &ImageListPanel::signalShowImage, this, &MainWindow::slotShowImage);
}

void MainWindow::slotFileOpen()
{
    QStringList fileList = QFileDialog::getOpenFileNames(this,
                                                    tr("Open Image Files"),
                                                    tr("../"),
                                                    tr("Image File(*.jpg *.jpeg *.png *.bmp)"));
    for(int i = 0; i < fileList.size(); i++)
    {
        QString filename = fileList.at(i);
        if (!filename.isEmpty())
        {
            pCController->getInstance()->loadImg(filename.toLatin1().data());
        }
    }
   updateImageListItem();
   slotShowImage(pInfoPanelsHolder->getImagesCount() - 1);
}

void MainWindow::updateImageListItem()
{
    std::vector<std::string> strlist = pCController->getInstance()->getTitleList();
    std::vector<std::string>::iterator it;
    QVector<QString> qStrlist;
    for(it = strlist.begin(); it != strlist.end(); it++)
    {
        qStrlist.push_back(QString::fromStdString(*it));
    }
    pInfoPanelsHolder->updateImageListItem(qStrlist);
}

void MainWindow::slotShowImage(int index)
{
    setCurSelectedIndex(index);
    pViewPanelsHolder->showImages(pCController->getInstance()->getImage(index));
}

void MainWindow::selectImageListItem(int index)
{
    pInfoPanelsHolder->selectImageListItem(index);
}

void MainWindow::setCurSelectedIndex(int index)
{
    this->curSelectedIndex = index;
}

int MainWindow::getCurSelectedIndex()
{
    return curSelectedIndex;
}
