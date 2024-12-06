#define UNTITLED_LIBRARY

#include "MainWidget.h"

#include "ClassTool.hpp"


MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
{
    Init(parent);
}

MainWidget::~MainWidget()
{

}

void MainWidget::Init(const QWidget* pParent)
{
    InitMainWidget(pParent);
    QVBoxLayout* qMainWidgetLayer = new QVBoxLayout();
    m_qMainToolBox = new MainToolBox(this);
    qMainWidgetLayer->setContentsMargins(15,20,15,10);
    qMainWidgetLayer->addWidget(m_qMainToolBox);
    this->setLayout(qMainWidgetLayer);
    
}
