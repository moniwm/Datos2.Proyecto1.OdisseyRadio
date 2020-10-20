/**
  * @brief Source file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MP3Player.h"

int const rowHeight = 31; /// Constant variable that stores the height of the table rows
int const minimumRows = 16; /// Minimum amount of rows without scrolling
int const minimumTableHeight = 500;

int extraRows;
int heightDifference;
int rowCount;


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Ui::MainWindow **ppUi = &ui;

    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint); // Set borderless window

    /**
     * This block code sets the width for each one of the columns of the table
     */

    ui->songsList->setColumnWidth(0, 275);
    ui->songsList->setColumnWidth(1, 163);
    ui->songsList->setColumnWidth(2, 100);
    ui->songsList->setColumnWidth(3, 100);

    extraRows = 0; ///This variable contains the extra amount of rows to be added depending on the window size

    mp3_player = new MP3Player(ppUi);
    MP3Player** pp_mp3_player = &mp3_player;

    duration_subject = new DurationSubject();
    duration_subject->Attach(pp_mp3_player);

    isPlaying = false;

    connect(mp3_player->getPlayer(), SIGNAL(positionChanged(qint64)), this, SLOT(on_positionChanged(qint64)));
    connect(mp3_player->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(on_durationChanged(qint64)));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_durationChanged(qint64 duration) {
    duration_subject->Notify(duration);
}

void MainWindow::on_playBtn_clicked() {
    if (isPlaying) {
        ui->playBtn->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        mp3_player->PauseSong();
    } else {
        ui->playBtn->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        mp3_player->PlaySong();
    }
    isPlaying = !isPlaying;
}

void MainWindow::on_infoBtn_clicked() {
    std::cout << "Get song info! \n";
}

void MainWindow::on_loadBtn_clicked() {
    std::cout << "Load library! \n";

}


void MainWindow::on_allBtn_stateChanged(int arg1) {
    if (ui->allBtn->isChecked()) {
        ui->album1Btn->setChecked(true);
        ui->album2Btn->setChecked(true);
        ui->album3Btn->setChecked(true);
        ui->album4Btn->setChecked(true);
        ui->album5Btn->setChecked(true);
        ui->album6Btn->setChecked(true);
    } else {
        ui->album1Btn->setChecked(false);
        ui->album2Btn->setChecked(false);
        ui->album3Btn->setChecked(false);
        ui->album4Btn->setChecked(false);
        ui->album5Btn->setChecked(false);
        ui->album6Btn->setChecked(false);
    }
}


void MainWindow::on_paginateBtn_clicked() {
    if (ui->paginateBtn->isChecked()) {
        std::cout << "Paginate memory \n";
    } else {
        std::cout << "Not paginate \n";
    }
}

/**
 * @brief This method calculates the amount of rows visible to the client without scrolling the list
 * @param event
 */
void MainWindow::resizeEvent(QResizeEvent *event) {

    heightDifference = MainWindow::size().height() - minimumHeight();
    extraRows = heightDifference / rowHeight;
    rowCount = minimumRows + extraRows;

    ui->songsList->setFixedHeight(minimumTableHeight + heightDifference);
    ui->songsList->setRowCount(rowCount);
}


/*!
 * Private slot. Updates song's slider position
 * @param position : qint64
 */
void MainWindow::on_positionChanged(qint64 position) {
    mp3_player->UpdateSlider(position);
}
