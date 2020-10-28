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

void Information::getInformation(QString title, QString genre, QString artist, QString length) {
    ui->label_artist->setText(artist);
    ui->label_genre->setText(genre);
    ui->label_length->setText(length);
    ui->label_title->setText(title);
}
