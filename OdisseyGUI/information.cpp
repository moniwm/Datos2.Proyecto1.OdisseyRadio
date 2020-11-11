/**
 * @brief This class creates a window that shows the information of the track that is currently playing
 * @author Monica Waterhouse
 *
 */

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

/**
 * Takes the parameters from the Main Window class according to the track that is currently playing
 * @param title
 * @param genre
 * @param artist
 * @param length
 */

void Information::getInformation(QString title, QString genre, QString artist, QString length) {
    ui->label_artist->setText(artist);
    ui->label_genre->setText(genre);
    ui->label_length->setText(length);
    ui->label_title->setText(title);
}
