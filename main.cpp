#include "mainwindow.h"
#include <QFile>
#include "Log.h"
#include <QDateTime>
#include <qdebug.h>
#include <QDir>
#include <QMessageBox>
#include <QApplication>
void create_filed()
{
    QDir *temp = new QDir;
    bool exist = temp->exists("temp");
    if(exist)
        return;
    else
    {
         temp->mkdir("temp");

    }

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("logo.png"));
    QFile qssFile("./qss/ui.qss");//资源文件":/css.qss"
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
    QString qss = QLatin1String(qssFile.readAll()); //读取
    qApp->setStyleSheet(qss);  //设置
    qDebug() << "qss："; qDebug() << qss;

    qssFile.close();
    }
    w.show();

    return a.exec();
}
