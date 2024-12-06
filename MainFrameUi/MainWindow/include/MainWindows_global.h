#ifndef MAINWIDGETS_GLOBAL_H
#define MAINWIDGETS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QWidget>
#include <QGuiApplication>
#include <QLineEdit>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QDebug> // 包含QDebug头文件，用于调试输出

#if defined(MAINWIDGETS_LIBRARY)
#  define MAINWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define MAINWIDGETS_EXPORT Q_DECL_IMPORT
#endif

#endif // MAINWIDGETS_GLOBAL_H
