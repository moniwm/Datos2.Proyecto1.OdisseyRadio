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
     * This block of code sets the width for each one of the columns of the table
     */

    ui->songsList->setColumnWidth(0, 275);
    ui->songsList->setColumnWidth(1, 163);
    ui->songsList->setColumnWidth(2, 100);
    ui->songsList->setColumnWidth(3, 100);

    //QPixmap play("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/play.png");
    QPixmap play("/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/play.png");
    QIcon playIcon(play);
    ui->playBtn->setIcon(playIcon);

    //ui->playBtn->setStyleSheet("qproperty-icon: url(:/path/to/images.png);");

    extraRows = 0; ///This variable contains the extra amount of rows to be added depending on the window size

    mp3_player = new MP3Player(ppUi);
    MP3Player** pp_mp3_player = &mp3_player;

    duration_subject = new DurationSubject();
    duration_subject->Attach(pp_mp3_player);

    is_playing = is_slider_pressed = false;

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
    if (is_playing) {

        //QPixmap play("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/play.png");
        QPixmap play ("/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/play.png");
        QIcon playIcon(play);
        ui->playBtn->setIcon(playIcon);

        mp3_player->PauseSong();
    } else {

        //QPixmap pause("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/pause.png");
        QPixmap pause("/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/pause.png");
        QIcon pauseIcon(pause);
        ui->playBtn->setIcon(pauseIcon);

        mp3_player->PlaySong();
    }
    is_playing = !is_playing;
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
    if (!is_slider_pressed)
        mp3_player->UpdateSlider(position);
    ui->lengthLabel->setText(SecondsToMinutes(position/1000));
}

void MainWindow::on_songControl_sliderPressed() {
    is_slider_pressed = true;
}

void MainWindow::on_songControl_sliderReleased() {
    is_slider_pressed = false;
    int position = ui->songControl->value();
    mp3_player->SliderMoved(position);
}

QString MainWindow::SecondsToMinutes(qint64 seconds) {
    int sec = seconds;
    QString mn = QString::number( (sec ) / 60);
    int _tmp_mn  = mn.toInt() * 60;
    QString sc= QString::number( (seconds- _tmp_mn  ) % 60 );

    return (mn.length() == 1 ? "0" + mn : mn ) + ":" + (sc.length() == 1 ? "0" + sc : sc);
}