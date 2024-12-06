#include "WidgetFactory.h"

class CWidgetAutoLoadMgr
{
public:
    static CWidgetAutoLoadMgr* GetInstance();

    IWidgetFactory* AutoLoadPlugin(const QString &);

    IWidgetFactory* AutoLoadPlugin(const int &);

    void GetPluginList(QStringList&);

private:
    CWidgetAutoLoadMgr();
    ~CWidgetAutoLoadMgr(){};
    CWidgetAutoLoadMgr(const CWidgetAutoLoadMgr &sc){}; //拷贝构造函数也需要设置为私有

    void LoadPluginInfo(const QString&);

private:
    static CWidgetAutoLoadMgr *g_pWidgetAutoLoadMgr;

    std::map<int, std::string> mapIndexToPlugin;

};