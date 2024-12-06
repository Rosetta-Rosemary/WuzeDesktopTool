#ifndef MAINTOOLBOOL_GLOBAL_H
#define MAINTOOLBOOL_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QWidget>
#include <QGuiApplication>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPushButton>
#include <QToolBox>
#include <QHBoxLayout> // 包含QHBoxLayout头文件，用于水平布局
#include <QTabWidget> // 包含QTabWidget头文件，用于创建标签页控件
#include <QDebug> // 包含QDebug头文件，用于调试输出

#if defined(MAINTOOLBOOL_LIBRARY)
#  define MAINTOOLBOOL_GLOBAL Q_DECL_EXPORT
#else
#  define MAINTOOLBOOL_GLOBAL Q_DECL_IMPORT
#endif




#endif // MAINTOOLBOOL_GLOBAL_H