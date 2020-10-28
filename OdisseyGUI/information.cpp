#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}


void Information::on_btn_close_clicked()
{
    this->close();
}
