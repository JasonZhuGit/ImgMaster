#ifndef FILELISTDOCKWIDGET_H
#define FILELISTDOCKWIDGET_H

#include <string>
#include <vector>
#include <QWidget>
#include <QDockWidget>
#include <QListWidget>
#include <QGridLayout>

using namespace std;
class FileListDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit FileListDockWidget(QWidget *parent = 0);
    QWidget * pBaseWidget;
    QListWidget * pFileList;
    QGridLayout * pMainLayout;

    void setupUi();
    void initConnect();
    void addImageList(std::vector<string> strlist);
    void selectBackImage();
    void setSelectImage(int index);
    void on_list_item_clicked(QListWidgetItem * item);

signals:
    void switchImageSignal(int index);

public slots:
};

#endif // FILELISTDOCKWIDGET_H
