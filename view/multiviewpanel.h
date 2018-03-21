#ifndef VIEWPANELMULTIPLE_H
#define VIEWPANELMULTIPLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <view/imageview.h>
#include <model/coreimage.h>

class MultiViewPanel : public QWidget
{
    Q_OBJECT
public:
    MultiViewPanel(QWidget *parent);
    ~MultiViewPanel();

    QVBoxLayout * partLayout;
    QHBoxLayout * mainLayout;

    QWidget * partWidget;
    ImageView * redView;
    ImageView * greenView;
    ImageView * blueView;
    ImageView * mainView;
    ImageView * histView;

    void setupUi();

    void showImages(CoreImage *pCoreImage);

};

#endif // VIEWPANELMULTIPLE_H
