#pragma once

#include <QtCore/qglobal.h>
#include <QWidget>
#include <QGuiApplication>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPushButton>
#include <QToolBox>
#include <QVBoxLayout> // 包含QHBoxLayout头文件，用于水平布局
#include <QTabWidget> // 包含QTabWidget头文件，用于创建标签页控件
#include <QFile>
#include <QMessageBox>
#include <QDebug> // 包含QDebug头文件，用于调试输出

#if defined(WIDGETFACTORY_LIBRARY)
#  define WIDGETFACTORY_GLOBAL Q_DECL_EXPORT
#else
#  define WIDGETFACTORY_GLOBAL Q_DECL_IMPORT
#endif