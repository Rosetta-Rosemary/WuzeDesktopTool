#pragma once

#include <QGuiApplication>
#include <QScreen>
#include <QStyleOption>
#include <QPainter>
#include <QPushButton>
#include <QString>

#define SYSTEMBUTTONSIZE 22
#define WIDGETBORDER 5
#define MAINWIDGETBORDER 3

// 默认桌面内居中显示
static void SetWindowCenter(QWidget *ThisWidget)
{
    int appWindowWidth = ThisWidget->geometry().width();
    int appWindowHeight = ThisWidget->geometry().height();

    QScreen* screen = QGuiApplication::primaryScreen();

    QRect rect2 = screen->availableGeometry();

    int center_y = (rect2.size().height())/2 - appWindowHeight/2;
    int center_x = (rect2.size().width())/2 - appWindowWidth/2;
    //此处的Width,Height不要被修改了(例如除以2了)
   //不然看起来不是居中的
    ThisWidget->setGeometry(center_x, center_y, 
                appWindowWidth,appWindowHeight);
};

// 清除边框
static void SetWindowFlgClr(QWidget *ThisWidget)
{
    ThisWidget->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

// 圆滑边框
static void SetCircleStyleSheet(QWidget *ThisWidget)
{
    //ThisWidget->setStyleSheet(QString::fromUtf8("border"));
}

// 获取退出按钮位置
static void GetExitButtonPos(const QWidget *ThisWidget, int &iPos_x, int &iPos_y)
{
    int appWindowWidth = ThisWidget->geometry().width();
    int appWindowHeight = ThisWidget->geometry().height();

    iPos_x = appWindowWidth - WIDGETBORDER - SYSTEMBUTTONSIZE;
    iPos_y = WIDGETBORDER;
}

// 获取最小化按钮位置
static void GetMinButtonPos(const QWidget *ThisWidget, int &iPos_x, int &iPos_y)
{
    int appWindowWidth = ThisWidget->geometry().width();
    int appWindowHeight = ThisWidget->geometry().height();

    iPos_x = appWindowWidth - WIDGETBORDER - SYSTEMBUTTONSIZE - WIDGETBORDER - SYSTEMBUTTONSIZE;
    iPos_y = WIDGETBORDER;
}

static void GetAddToolBoxItemButtonPos(const QWidget *ThisWidget, int &iPos_x, int &iPos_y)
{
    int appWindowWidth = ThisWidget->geometry().width();
    int appWindowHeight = ThisWidget->geometry().height();

    iPos_x = appWindowWidth - WIDGETBORDER - SYSTEMBUTTONSIZE - WIDGETBORDER - SYSTEMBUTTONSIZE - WIDGETBORDER - SYSTEMBUTTONSIZE;
    iPos_y = WIDGETBORDER;
}

//
static void GetMainWidgetGeometry(const QWidget *ThisWidget, 
                                    int &iPos_x, int &iPos_y, 
                                    int &iWidth, int &iHeight)
{
    iPos_x = MAINWIDGETBORDER;
    // iPos_y = MAINWIDGETBORDER + /*SYSTEMBUTTONSIZE*/ + WIDGETBORDER;
    iPos_y = MAINWIDGETBORDER;
    int appWindowWidth = ThisWidget->geometry().width();
    int appWindowHeight = ThisWidget->geometry().height();
    iWidth = appWindowWidth - iPos_x - MAINWIDGETBORDER;
    iHeight = appWindowHeight - iPos_y - MAINWIDGETBORDER;
}