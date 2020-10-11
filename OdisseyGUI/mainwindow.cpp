/**
  * @brief Source file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int const rowHeight = 31; /// Constant variable that stores the height of the table rows
int  const minimumRows = 16; /// Minimum amount of rows without scrolling
int const minimumTableHeight = 500;

int extraRows;
int heightDifference;
int rowCount;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint); // Set borderless window

    /**
     * This block code sets the width for each one of the columns of the table
     */

    ui->songsList->setColumnWidth(0, 275);
    ui->songsList->setColumnWidth(1, 163);
    ui->songsList->setColumnWidth(2, 100);
    ui->songsList->setColumnWidth(3, 100);

   extraRows = 0; /// This variable contains the extra amount of rows to be added depending on the window size

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playBtn_clicked()
{
    std::cout << "Play music! \n";
}

void MainWindow::on_infoBtn_clicked()
{
    std::cout << "Get song info! \n";
}

void MainWindow::on_loadBtn_clicked()
{
    std::cout << "Load library! \n";

}


void MainWindow::on_allBtn_stateChanged(int arg1)
{
    if(ui->allBtn->isChecked()){
        ui->album1Btn->setChecked(true);
        ui->album2Btn->setChecked(true);
        ui->album3Btn->setChecked(true);
        ui->album4Btn->setChecked(true);
        ui->album5Btn->setChecked(true);
        ui->album6Btn->setChecked(true);
    }

    else{
        ui->album1Btn->setChecked(false);
        ui->album2Btn->setChecked(false);
        ui->album3Btn->setChecked(false);
        ui->album4Btn->setChecked(false);
        ui->album5Btn->setChecked(false);
        ui->album6Btn->setChecked(false);
    }
}


void MainWindow::on_paginateBtn_clicked()
{
    if(ui->paginateBtn->isChecked()){
        std::cout << "Paginate memory \n";
    }

    else{
        std::cout << "Not paginate \n";
    }
}

/**
 * @brief This method calculates the amount of rows visible to the client without scrolling the list
 * @param event
 */
void MainWindow::resizeEvent(QResizeEvent *event) {

    heightDifference = MainWindow::size().height() - minimumHeight();
    extraRows = heightDifference/rowHeight;
    rowCount = minimumRows + extraRows;

    ui->songsList->setFixedHeight(minimumTableHeight + heightDifference);
    ui->songsList->setRowCount(rowCount);
}
