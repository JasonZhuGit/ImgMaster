#ifndef BASEPROCPANEL_H
#define BASEPROCPANEL_H

//#include <mainwindow.h>
#include <QWidget>

namespace Ui {
class BaseProcPanel;
}

class BaseProcPanel : public QWidget
{
    Q_OBJECT

public:
    explicit BaseProcPanel(QWidget *parent = 0);
    ~BaseProcPanel();

    QWidget * pParent;

signals:
    void file_open_signal();

private slots:
    void on_btn_open_clicked();
 
private:
    Ui::BaseProcPanel *ui;
};

#endif // BASEPROCPANEL_H
