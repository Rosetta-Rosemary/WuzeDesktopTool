#include "WidgetAutoLoadMgr.h"
#include <QDir>
#include <QFile>

CWidgetAutoLoadMgr *CWidgetAutoLoadMgr::g_pWidgetAutoLoadMgr = nullptr;

CWidgetAutoLoadMgr* CWidgetAutoLoadMgr::GetInstance()
{
	if (g_pWidgetAutoLoadMgr == nullptr)
	{
		g_pWidgetAutoLoadMgr = new CWidgetAutoLoadMgr();
	}
	return g_pWidgetAutoLoadMgr;
}

CWidgetAutoLoadMgr::CWidgetAutoLoadMgr()
{
    LoadPluginInfo("/plugin/");
}

void CWidgetAutoLoadMgr::LoadPluginInfo(const QString& strFiledir)
{
    QString exeDir = QCoreApplication::applicationDirPath();
	QString strFolder = exeDir.append(strFiledir);
	strFolder = QDir::toNativeSeparators(strFolder);
		// 获取所有文件夹名
	QDir dir(strFolder);
	if (dir.exists())
    {
        QStringList mImgNames = QStringList("");
    
	    mImgNames = dir.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);
        bool bNotDisplayFuncPage = false;
        if (mImgNames.size() != 1)
        {
            bNotDisplayFuncPage = true;
        }
        for (int i = 0; i < mImgNames.size(); ++i)
        {
            QString strFileName = strFiledir + mImgNames[i];
            // if (strFileName.indexOf("StandFuncPage") >= 0 && bNotDisplayFuncPage)
            // {
            //     continue;
            // }
            mapIndexToPlugin[i] = strFileName.toStdString();
        }
    }
}

void CWidgetAutoLoadMgr::GetPluginList(QStringList &PluginList)
{
    std::map<int, std::string>::iterator itFind ;
    for (itFind = mapIndexToPlugin.begin(); itFind != mapIndexToPlugin.end(); itFind++)
    {
        QString qstrPluginName = QString::fromStdString(itFind->second);
        PluginList.push_back(qstrPluginName);
    }
}

IWidgetFactory* CWidgetAutoLoadMgr::AutoLoadPlugin(const QString &index)
{
    QObject *obj=NULL;
    QString strPluginPath = QCoreApplication::applicationDirPath();
    strPluginPath += index;
    QPluginLoader pluginLoader(strPluginPath);
    obj=pluginLoader.instance();
    if(obj!=NULL)
    {
        IWidgetFactory* qWidget = qobject_cast<IWidgetFactory *>(obj);
        if(qWidget)
        {
            return qWidget;
        }
    }

    return nullptr;
    
}

IWidgetFactory* CWidgetAutoLoadMgr::AutoLoadPlugin(const int &index)
{
    std::map<int, std::string>::iterator itFind = mapIndexToPlugin.find(index);
    if (itFind == mapIndexToPlugin.end())
    {
        return nullptr;
    }
    QString qstrPluginName = QString::fromStdString(itFind->second);

    QObject *obj=NULL;
    QString strPluginPath = QCoreApplication::applicationDirPath();
    strPluginPath += qstrPluginName;
    QPluginLoader pluginLoader(strPluginPath);
    obj=pluginLoader.instance();
    if(obj!=NULL)
    {
        IWidgetFactory* qWidget = qobject_cast<IWidgetFactory *>(obj);
        if(qWidget)
        {
            return qWidget;
        }
    }

    return nullptr;
    
}