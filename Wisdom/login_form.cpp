#include "login_form.h"
#include "ui_login_form.h"

login_form::login_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_form)
{
    ui->setupUi(this);
}

login_form::~login_form()
{
    delete ui;
}
