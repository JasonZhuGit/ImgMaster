#ifndef IMAGELISTPANEL_H
#define IMAGELISTPANEL_H

#include <QVector>
#include <QString>
#include <QWidget>
#include <QListWidget>
#include <QGridLayout>

class ImageListPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ImageListPanel(QWidget *parent = 0);

    QListWidget * pImageList;
    QGridLayout * pMainLayout;

    void setupUi();
    void initConnect();
    void setImageList(QVector<QString> strlist);
    void selectImageListItem(int index);

signals:
    void signalShowImage(int index);

public slots:
    void onItemClicked(QListWidgetItem *item);

};

#endif // IMAGELISTPANEL_H
