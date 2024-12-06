#pragma once

#include "MainToolBox_global.h"

class MainToolBox : public QToolBox
{
    Q_OBJECT

public:
    MainToolBox(QWidget *parent = nullptr) : QToolBox(parent)
    {
        InitUi();
        InitChildWidget();
    };

    ~MainToolBox(){};


private:
    void InitUi();

    void InitChildWidget();

};