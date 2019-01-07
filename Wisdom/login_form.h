#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>

namespace Ui {
class login_form;
}

class login_form : public QDialog
{
    Q_OBJECT

public:
    explicit login_form(QWidget *parent = 0);
    ~login_form();

private:
    Ui::login_form *ui;
};

#endif // LOGIN_FORM_H
