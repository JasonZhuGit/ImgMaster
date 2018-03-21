#include "baseprocpanel.h"
#include "ui_baseprocpanel.h"

BaseProcPanel::BaseProcPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseProcPanel)
{
    pParent = parent;
    ui->setupUi(this);
}

BaseProcPanel::~BaseProcPanel()
{
    delete ui;
}

void BaseProcPanel::on_btn_open_clicked()
{
    emit file_open_signal();
}
