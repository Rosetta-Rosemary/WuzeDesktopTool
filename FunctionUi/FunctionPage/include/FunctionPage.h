#pragma once

#include "WidgetFactory.h"
#include "ComponentFactory.h"

#if defined(FUNCTIONPAGE_LIBRARY)
#  define FUNCTIONPAGE_GLOBAL Q_DECL_EXPORT
#else
#  define FUNCTIONPAGE_GLOBAL Q_DECL_IMPORT
#endif


namespace FunctionPageSpace
{
    static const QString PageTabName = "功能页";
    static const QIcon::ThemeIcon IconType = QIcon::ThemeIcon::DocumentNew;
}


class CFunctionPage : public IWidgetFactory
{
    Q_OBJECT

    Q_INTERFACES(IWidgetFactory)

    Q_PLUGIN_METADATA(IID QTPLUGIN_IWIDGETFACTORY_IID)

public:
    CFunctionPage(QWidget *parent = nullptr) : IWidgetFactory(parent)
    {
        InitUi();
    };

    ~CFunctionPage(){};

    QString GetPageTabName();

    QIcon::ThemeIcon GetThemeIcon();

private:
    void InitUi();
};
