#ifndef PROCPANELSHOLDER_H
#define PROCPANELSHOLDER_H

#include <QDebug>
#include <QStackedWidget>
#include <QGridLayout>
#include <view/baseprocpanel.h>

class ProcPanelsHolder : public QStackedWidget
{
    Q_OBJECT
public:
    explicit ProcPanelsHolder(QWidget *parent = 0);
    int curIndex;
    QWidget * pParent;
    BaseProcPanel * pBasePanel;

    void setupUi();
    void initConnect();
    void file_open_action();

signals:
    void file_open_signal();
signals:

public slots:
};

#endif // PROCPANELSHOLDER_H
