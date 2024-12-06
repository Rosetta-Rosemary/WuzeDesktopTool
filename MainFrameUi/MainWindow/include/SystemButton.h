#pragma once

#include "MainWindows_global.h"

class MainWindowButton : public QPushButton
{
    Q_OBJECT

public:
    MainWindowButton(QWidget *parent = nullptr) : QPushButton(parent){};
    ~MainWindowButton(){};

    virtual void LoadStyleSheet(const QString &strStyleSheetFileDir);
};

class WidgetExitButton : public MainWindowButton
{
public:
    explicit WidgetExitButton(QWidget *parent = nullptr);
    ~WidgetExitButton();
};

class WidgetMinimizationButton : public MainWindowButton
{
    Q_OBJECT

public:
    explicit WidgetMinimizationButton(QWidget *parent = nullptr);
    ~WidgetMinimizationButton();

};
