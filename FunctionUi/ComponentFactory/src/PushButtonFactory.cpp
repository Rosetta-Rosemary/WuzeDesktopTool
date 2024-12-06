#include "ComponentFactory.h"

CCrystalPushbutton::CCrystalPushbutton(QWidget *parent) : QPushButton(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setMinimumHeight(30);
    this->setStyleSheet(LoadStyleSheet("CrystalPushButton.qss"));
    //this->show();
}
 
CCrystalPushbutton::~CCrystalPushbutton()
{
    
}

void CCrystalPushbutton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

}
