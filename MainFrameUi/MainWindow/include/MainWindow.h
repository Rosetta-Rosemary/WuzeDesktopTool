#pragma once

#include "MainWindows_global.h"
#include "SystemButton.h"

class MainWindow : public QMainWindow 
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void ResizeWidget(const QPoint &NewEndPos);
private:
    void Init();

private:
    QPushButton *m_Exit;
    QPushButton *m_Minimization;
    QPushButton *m_Add;
    QWidget *m_Main;

    QPoint mousePoint;
    bool mouse_press_to_mov;
    bool mouse_press_to_resize;
};