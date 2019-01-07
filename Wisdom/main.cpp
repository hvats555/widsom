#include "choosebook.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QDesktopWidget>
#include <QDebug>
#include <parser.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    choosebook w;
    w.setWindowTitle("Wisdom - Discover something new");

    QPixmap pix(":/images/rec/splashscreen.jpg");

    splash->setPixmap(pix.scaled(899, 600, Qt::KeepAspectRatio));
    splash->show();


    QTimer::singleShot(10000,splash,SLOT(close()));
    QTimer::singleShot(10000,&w,SLOT(show()));
    //w.show();

    return a.exec();
}
