/**
  * @brief Source file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    /**
     * This block code sets the width for each one of the columns of the table
     */

    ui->songsList->setColumnWidth(0, 275);
    ui->songsList->setColumnWidth(1, 163);
    ui->songsList->setColumnWidth(2, 100);
    ui->songsList->setColumnWidth(3, 100);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_closeBtn_clicked()
{
    this->close();
}


void MainWindow::on_playBtn_clicked()
{
    std::cout << "Play music!";
}

void MainWindow::on_infoBtn_clicked()
{
    std::cout << "Get song info!";
}

void MainWindow::on_loadBtn_clicked()
{
    std::cout << "Load library!";

}
