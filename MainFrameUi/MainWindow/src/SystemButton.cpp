#define UNTITLED_LIBRARY

#include "SystemButton.h"
#include "ClassTool.hpp"

void MainWindowButton::LoadStyleSheet(const QString &strStyleSheetFileDir)
{
    QFile file(strStyleSheetFileDir);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());//读取样式表文件
        this->setStyleSheet(styleSheet);//把文件内容传参
        file.close();
    }
    else
    {
        QMessageBox::information(this,"tip","cannot find qss file");
    }
}

WidgetExitButton::WidgetExitButton(QWidget *parent) : MainWindowButton(parent)
{
    this -> raise();
    int iPos_x;
    int iPos_y;
    GetExitButtonPos(parent, iPos_x, iPos_y);
    this -> setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);

    // 设置按钮初始样式
    QString path = QCoreApplication::applicationDirPath();
    path += "/resource/qss/ExitButton.qss";
    this->LoadStyleSheet(path);
    
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

    this->setIcon(closePix);
    this->setToolTip(tr("CLOSE"));
    this->setIconSize(QSize(20,20));
    //this->show();
}
 
WidgetExitButton::~WidgetExitButton()
{
    
}

WidgetMinimizationButton::WidgetMinimizationButton(QWidget *parent) : MainWindowButton(parent)
{
    this -> raise();
    int iPos_x;
    int iPos_y;
    GetMinButtonPos(parent, iPos_x, iPos_y);
    this -> setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);

    QString path = QCoreApplication::applicationDirPath();
    path += "/resource/qss/MinimizationButton.qss";
    this->LoadStyleSheet(path);

    QPixmap MinPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);

    this->setIcon(MinPix);
    this->setToolTip(tr("Min"));
    this->setIconSize(QSize(20,20));
    //this->show();
}
 
WidgetMinimizationButton::~WidgetMinimizationButton()
{
    
}