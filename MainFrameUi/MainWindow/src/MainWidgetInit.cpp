#define UNTITLED_LIBRARY

#include "MainWidget.h"
#include "ClassTool.hpp"
#include <QRegularExpressionValidator>


void MainWidget::InitMainWidget(const QWidget* pParent)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color:rgb(248,248,248);border-radius:9px"); // 背景色定为 灰阶 #F8F8F8
    this->setWindowOpacity(0.5);
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}