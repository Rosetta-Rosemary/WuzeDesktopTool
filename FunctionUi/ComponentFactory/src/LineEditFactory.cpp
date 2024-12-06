#include "ComponentFactory.h"

CMacOSLineEdit::CMacOSLineEdit(QWidget *parent) : QLineEdit(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setMinimumSize(0, 30);
    this->setAlignment(Qt::AlignCenter);
    this->setStyleSheet(LoadStyleSheet("MacOS_LineEdit.qss"));
}
 
CMacOSLineEdit::~CMacOSLineEdit()
{
    
}

void CMacOSLineEdit::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

QString LoadStyleSheet(const QString &strQssFile)
{
    QString styleSheet;
    QString strStyleSheetFileDir = QCoreApplication::applicationDirPath();
    strStyleSheetFileDir += "/resource/qss/";
    strStyleSheetFileDir += strQssFile;
    QFile file(strStyleSheetFileDir);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        styleSheet += QLatin1String(file.readAll());//读取样式表文件
        file.close();
    }
    else
    {
        qDebug() << "Init cannot find qss file: " <<  strStyleSheetFileDir;
    }
    return styleSheet;
};