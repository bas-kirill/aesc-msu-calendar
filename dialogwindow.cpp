#include "dialogwindow.h"
#include "ui_dialogwindow.h"

DialogWindow::DialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindow)
{
    ui->setupUi(this);
}

DialogWindow::~DialogWindow()
{
    delete ui;
}
void DialogWindow::set_note(QString str) {
    ui->lineEdit->setText(str);
}
QString DialogWindow::note() {
    return(ui->lineEdit->text());
}
