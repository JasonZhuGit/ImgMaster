#include "procpanelsholder.h"

ProcPanelsHolder::ProcPanelsHolder(QWidget *parent) : QStackedWidget(parent)
{
    curIndex = 0;
    this->pParent = parent;
    setupUi();
    initConnect();
}


void ProcPanelsHolder::setupUi()
{
    this->setFrameStyle(QFrame::StyledPanel);
    this->setMaximumWidth(200);
    this->setMinimumWidth(200);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
    pBasePanel = new BaseProcPanel(pParent);
    this->addWidget(pBasePanel);
    this->setCurrentIndex(curIndex);
}

void ProcPanelsHolder::initConnect()
{
    //connect(pBasePanel, &BaseProcPanel::file_open_signal, this, &ProcPanelsHolder::file_open_action);
}


void ProcPanelsHolder::file_open_action()
{
    //emit file_open_signal();
}
