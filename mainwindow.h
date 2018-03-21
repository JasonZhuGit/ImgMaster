#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <view/infopanelsholder.h>
#include <view/procpanelsholder.h>
#include <view/viewpanelsholder.h>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QToolBar>
#include <QFileDialog>
#include <QDockWidget>

#include <controller/corecontroller.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget * pCentralWidget;
    QHBoxLayout * pMainLayout;

    InfoPanelsHolder * pInfoPanelsHolder;
    ProcPanelsHolder * pProcPanelsHolder;
    ViewPanelsHolder * pViewPanelsHolder;

    QMenuBar * pMainMenuBar; //qt just have one menubar as a widget, and other menu is draw in the same menu bar
    QMenu * pFileMenu;
    QMenu * pPanelsMenu;
    QToolBar * pFileToolBar;//there is not maintoolbar, every toolbar is an widget
    QToolBar * pPanelsToolBar;

    QAction * fileOpenAction;
    QAction * fileSaveAction;

    int curSelectedIndex;
    void setupUi();
    void initWidgets();
    void initAction();
    void initMenuBar();
    void initToolBar();
    void initConnect();

    CoreController * pCController;

    void setCurSelectedIndex(int index);
    int getCurSelectedIndex();
    void showImageBack();
    void updateImageListItem();
    void selectBackImg();
    void showImageChannels(int index);
    void selectImageListItem(int index);

private slots:
    void slotFileOpen();
    void slotShowImage(int index);
};

#endif // MAINWINDOW_H
