#include "bookdetails.h"
#include "ui_bookdetails.h"
#include "parser.h"
#include "download.h"
#include <QDebug>
#include <QPixmap>
#include <QUrl>
#include <QDesktopServices>
#include <QFile>

parser book;

bookdetails::bookdetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookdetails)
{
    ui->setupUi(this);
    book.parse();
    ui->title->setText(book.bookTitle);
    ui->author->setText(book.author);
    ui->publisher->setText(book.publisher);
    ui->catagory->setText(book.catagory);
    ui->page_count->setText(book.pageCount);
    ui->publishdate->setText(book.publisheDate);
    ui->description->setText(book.description);

    QPixmap pix(":/images/rec/book.png");
    ui->book->setPixmap(pix.scaled(100, 150, Qt::KeepAspectRatio));
}

bookdetails::~bookdetails()
{
    delete ui;
}

void bookdetails::on_buy_now_clicked()
{
    QString url = "https://www.paypal.me/hvats";
    QDesktopServices::openUrl(QUrl(url));

    QFile file("C:/wisdom/response/api_response.json");
    file.remove();

}
