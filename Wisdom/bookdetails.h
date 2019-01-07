#ifndef BOOKDETAILS_H
#define BOOKDETAILS_H

#include <QDialog>

namespace Ui {
class bookdetails;
}

class bookdetails : public QDialog
{
    Q_OBJECT

public:
    explicit bookdetails(QWidget *parent = 0);
    ~bookdetails();

private slots:

    void on_buy_now_clicked();

private:
    Ui::bookdetails *ui;
};

#endif // BOOKDETAILS_H
