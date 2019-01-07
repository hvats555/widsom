#include "choosebook.h"
#include "ui_choosebook.h"
#include "download.h"
#include "delay.h"
#include <QPixmap>
#include <QPalette>
#include <QThread>
#include <QCoreApplication>
#include <QTime>

download jsonResponse;
delay d;

choosebook::choosebook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choosebook)
{
    ui->setupUi(this);
    this->setFixedSize(size());

    QPixmap pix(":/images/rec/c.jpg");
    pix.scaled(400,400, Qt::KeepAspectRatio);
    ui->background_image->setPixmap(pix);
    //QPalette palette;
    //palette.setBrush(QPalette::Background, pix);
    //this->setPalette(palette);



   }

void delay(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

choosebook::~choosebook()
{
    delete ui;
}

void choosebook::on_pushButton_isbnSubmit_clicked()
{
    QString apiLink = "https://www.googleapis.com/books/v1/volumes?q=";
    QString searchQuery = ui->lineEdit_isbnInput->text();
    QString url = apiLink + searchQuery;

    jsonResponse.doDownload(url, "json");
    d.wait(10);


    bk = new bookdetails(this);
    choosebook::close();
    bk->show();
}














