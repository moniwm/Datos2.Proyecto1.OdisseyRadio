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

void Information::getInformation(std::string title, std::string genre, std::string artist, std::string length) {
    ui->label_artist->setText(QString::fromStdString(artist));
    ui->label_genre->setText(QString::fromStdString(genre));
    ui->label_length->setText(QString::fromStdString(length));
    ui->label_title->setText(QString::fromStdString(title));
}
