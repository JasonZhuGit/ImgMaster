#ifndef INFOPANELSHOLDER_H
#define INFOPANELSHOLDER_H

#include <QString>
#include <QVector>
#include <QStackedWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <view/imagelistpanel.h>

using namespace std;

class InfoPanelsHolder : public QStackedWidget
{
    Q_OBJECT
public:
    explicit InfoPanelsHolder(QWidget *parent = 0);
    int curIndex;
    QWidget * pParent;
    ImageListPanel * pImageListPanel;

    void setupUi();
    void updateImageListItem(QVector<QString> strlist);
    void setSelectImage(int index);
    int getImagesCount();
    void selectImageListItem(int index);

signals:

public slots:
};

#endif // INFOPANELSHOLDER_H
