#include "WidgetFactory.h"

void IWidgetFactory::InitUi()
{
    this->setStyleSheet("background-color:#CACACA;"); // 设置widget1的背景颜色为深灰色
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //this->show();
}

