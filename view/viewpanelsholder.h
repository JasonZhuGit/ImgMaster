#ifndef VIEWPANELSHOLDER_H
#define VIEWPANELSHOLDER_H

#include <QStackedWidget>
#include <view/multiviewpanel.h>
#include <model/coreimage.h>

class ViewPanelsHolder : public QStackedWidget
{
    Q_OBJECT
public:
    explicit ViewPanelsHolder(QWidget * parent = 0);
    ~ViewPanelsHolder();

    int curIndex;
    MultiViewPanel * pMultiViewPanel;

    void setupUi();

    void showImages(CoreImage *pCoreImage);

signals:

public slots:

};

#endif // VIEWPANELSHOLDER_H
