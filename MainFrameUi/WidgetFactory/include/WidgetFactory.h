#pragma once

#include "WidgetFactory_global.h"
#include <QtPlugin>
#include <QPluginLoader>

class IWidgetFactory : public QWidget
{
    Q_OBJECT

public:
    IWidgetFactory(QWidget *parent = nullptr) : QWidget(parent){};

    ~IWidgetFactory(){};

    virtual void InitUi();

    virtual QString GetPageTabName() = 0;

    virtual QIcon::ThemeIcon GetThemeIcon() = 0;
private:


};

#define QTPLUGIN_IWIDGETFACTORY_IID "plugin.widgetfactory.FunctoinPage"


Q_DECLARE_INTERFACE (IWidgetFactory, QTPLUGIN_IWIDGETFACTORY_IID)
