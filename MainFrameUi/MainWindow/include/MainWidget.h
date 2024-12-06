#pragma once

#include "MainWindows_global.h"
#include "MainToolBox.h"

class MainWidget : public QWidget 
{
    Q_OBJECT

public:
    MainWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~MainWidget();

    
private:
    void Init(const QWidget* pParent);

    void InitMainWidget(const QWidget* pParent);

    MainToolBox* m_qMainToolBox;
};