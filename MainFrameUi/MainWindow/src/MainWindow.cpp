#define UNTITLED_LIBRARY

#include "MainWindow.h"
#include "MainWidget.h"
#include "ClassTool.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    //setMaximumSize(800,800);
    setMinimumSize(390,650);
    setFixedSize(390,650);
    
    this->setStyleSheet("background-color:#DCDCDC;border-radius:12px");
    Init();
}

MainWindow::~MainWindow()
{
    m_Exit->deleteLater();
    m_Minimization->deleteLater();
    m_Main->deleteLater();
}

void MainWindow::Init()
{
    mouse_press_to_mov = false;
    mouse_press_to_resize = false;
    m_Exit = new WidgetExitButton(this);
    m_Minimization = new WidgetMinimizationButton(this);
    //m_Add = new WidgetAddToolBoxItemButton(this);

    connect(m_Exit,         &QPushButton::clicked, this,   [=](){this->close();});
    connect(m_Minimization, &QPushButton::clicked, this,   [=](){this->showMinimized();});

    QWidget* centralWidget = new QWidget(this);
    {
        QHBoxLayout* qMainLayerout = new QHBoxLayout();
        qMainLayerout->setContentsMargins(5,5,5,5);
        m_Main = new MainWidget(this);
        //m_Main->show();
        qMainLayerout->addWidget(m_Main);
        centralWidget->setLayout(qMainLayerout);
    }
    setCentralWidget(centralWidget);
    m_Exit->raise();
    m_Minimization->raise();
    
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制样式
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);//绘制样式
 
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);
 
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    //设置边框为圆角12px
    painter.drawRoundedRect(bmp.rect(), 12, 12);
    setMask(bmp);
    QWidget::paintEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
 
    if( (event->button() == Qt::LeftButton))
    {
        QPoint pos = event->pos();
        int PosX = pos.x();
        int PosY = pos.y();
        if (PosY >=0 && PosY <= 27)
        {
            std::cout << "mouse_press_to_mov Event" << std::endl;
            mouse_press_to_mov = true;
            mousePoint = event->globalPosition().toPoint() - this->pos();
        } 
        // event->accept();
        if ((PosX >= (this->width() - 30) && PosX <= (this->width()))
        && (PosY >= (this->height() - 30) && PosY <= (this->height())))
        {
            std::cout << "mouse_press_to_resize Event" << std::endl;
            mouse_press_to_resize = true;
            mousePoint = event->globalPosition().toPoint() - this->pos();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press_to_mov)
    {
        move(event->globalPosition().toPoint() - mousePoint);
    }
    if (mouse_press_to_resize)
    {
        ResizeWidget(event->globalPosition().toPoint());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press_to_mov = false;
    mouse_press_to_resize = false;
}

void MainWindow::ResizeWidget(const QPoint &NewEndPos)
{
    // ResizeWidget
    int iWidth = NewEndPos.x() - this->x();
    
    if (iWidth >= 390 && iWidth <= 480)
    {
        if (iWidth <= 390)
        {
            iWidth = 390;
        }
        else if (iWidth >= 480)
        {
            iWidth = 480;
        }

        int iHight = iWidth / 3 * 5;
        std::cout << "mouse_press_to_resize Event [" << iWidth << "] [" << iHight << "]"<< std::endl;
        setFixedSize(iWidth, iHight);

        int iPos_x = 0;
        int iPos_y = 0;
        int ix = 0;
        int iy = 0;
        GetMainWidgetGeometry(this, iPos_x, iPos_y, ix, iy);
        // std::cout << "GetMainWidgetGeometry[" << iWidth << "] [" << iHight << "]"<< std::endl;
        // m_Main->setFixedSize(ix, iy);
        // m_Main->setGeometry(iPos_x, iPos_y, ix, iy);  

        GetExitButtonPos(this, iPos_x, iPos_y);
        m_Exit->setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);

        GetMinButtonPos(this, iPos_x, iPos_y);
        m_Minimization -> setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);
    }
}
