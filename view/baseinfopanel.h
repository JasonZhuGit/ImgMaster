#ifndef BASEINFOPANEL_H
#define BASEINFOPANEL_H

#include <string>
#include <vector>
#include <QWidget>
#include <QListWidget>
#include <QGridLayout>
#include <QDebug>
#include <view/imageview.h>

using namespace std;
class BaseInfoPanel : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfoPanel(QWidget *parent = 0);

    QListWidget * pImgList;
    ImageView * redChannel;
    ImageView * greenChannel;
    ImageView * blueChannel;
    ImageView * histogram;
    QGridLayout * pMainLayout;

    void setupUi();
    void initConnect();
    void addImageList(std::vector<string> strlist);
    void selectBackImage();
    void setSelectImage(int index);
    void showImageChannels(cv::Mat & img);

signals:
    void switchImageSignal(int index);

public slots:
    void on_list_item_clicked(QListWidgetItem *item);

};

#endif // BASEINFOPANEL_H
