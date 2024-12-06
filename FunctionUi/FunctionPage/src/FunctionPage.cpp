#include "FunctionPage.h"

void CFunctionPage::InitUi()
{
    IWidgetFactory::InitUi();
}

QString CFunctionPage::GetPageTabName()
{
    return FunctionPageSpace::PageTabName;
}

QIcon::ThemeIcon CFunctionPage::GetThemeIcon()
{
    return FunctionPageSpace::IconType;
}
