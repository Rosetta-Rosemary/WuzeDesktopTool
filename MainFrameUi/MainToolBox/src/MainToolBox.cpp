#include "MainToolBox.h"
#include "WidgetAutoLoadMgr.h"

static const int G_INT_EDGE_DIST = 10; // 5px
static const int G_INT_DEFAULT_WIDTH = 400; // 400px
static const int G_INT_DEFAULT_HEIGTH = 300; // 300px

void MainToolBox::InitUi()
{
    //this->setContentsMargins(5, 15, 5, 10);
    this->setContextMenuPolicy(Qt::DefaultContextMenu);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setStyleSheet("QToolBox::tab {height: 15px;}");
}

void MainToolBox::InitChildWidget()
{
    QStringList Pluginlist;
    CWidgetAutoLoadMgr::GetInstance()->GetPluginList(Pluginlist);
    for (int i = 0; i < Pluginlist.size(); ++i)
    {
        IWidgetFactory* widget = CWidgetAutoLoadMgr::GetInstance()->AutoLoadPlugin(i); // 创建一个QWidget对象
        if (widget)
        {
            this->addItem(widget, widget->GetPageTabName());
            this->setItemIcon(i, QIcon::fromTheme(widget->GetThemeIcon()));
        }
    }
}