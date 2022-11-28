#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString locale;
    QTranslator tsor;
    locale = a.applicationDirPath()+"/"+"en.qm";
    tsor.load(locale);
    a.installTranslator(&tsor);

    MainWindow win;
    //w.setWindowState(Qt::WindowMaximized);//最大化显示
    win.resize(860,600);
    win.show();

    return a.exec();
}
