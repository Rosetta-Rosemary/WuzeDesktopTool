#pragma once

#include <QtCore/qglobal.h>
#include <QLineEdit>
#include <QPushButton>
#include <QToolBox>
#include <QFile>
#include <QGuiApplication>

QString LoadStyleSheet(const QString &strQssFile);

class CCrystalPushbutton : public QPushButton
{
    Q_OBJECT

public:
    explicit CCrystalPushbutton(QWidget *parent = nullptr);
    ~CCrystalPushbutton();
    void paintEvent(QPaintEvent *event);

private:
    QString m_strUrl;
};

class CMacOSLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit CMacOSLineEdit(QWidget *parent = nullptr);
    ~CMacOSLineEdit();

protected:
    void resizeEvent(QResizeEvent *event);
};