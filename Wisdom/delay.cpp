#include "delay.h"

delay::delay()
{

}

void delay::wait(int n){
    QTime dieTime= QTime::currentTime().addSecs(n);

    while (QTime::currentTime() < dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
