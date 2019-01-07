#ifndef CHOOSEBOOK_H
#define CHOOSEBOOK_H

#include <QDialog>
#include <bookdetails.h>

namespace Ui {
class choosebook;
}

class choosebook : public QDialog
{
    Q_OBJECT

public:
    explicit choosebook(QWidget *parent = 0);
    ~choosebook();

public slots:
   void on_pushButton_isbnSubmit_clicked();

public:

private:
    Ui::choosebook *ui;
    bookdetails *bk;
};

#endif // CHOOSEBOOK_H
