//
// Created by Luis Pedro Morales on 19/10/20.
//Class in charge of providing methods to play, pause, fast-forward/backward the selected song
//

#include "MP3Player.h"

MP3Player::MP3Player(Ui::MainWindow **ppUi) {
    file_path = "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/project1_resources/fma_small/001/001039.mp3";
    player = new QMediaPlayer();
    player->setNotifyInterval(50);
    //QString fileName = QFileDialog::getOpenFileName(this, "Choose a file", ".mp3");
    player->setMedia(QUrl::fromLocalFile(file_path));
    ui = *ppUi;
}

MP3Player::~MP3Player() {
    delete player;
    delete this;
}

QMediaPlayer *MP3Player::getPlayer() const {
    return player;
}


/*!
 * Updates the current_time of the slider depending on the current time (milliseconds) that the song has been played
 * @param time : int
 * @return current_time : int
 */

void MP3Player::UpdateSlider(qint64 current_time) {

    current_pos = 100*current_time/song_duration;
    ui->songControl->setValue(current_pos);

}

Ui::MainWindow *MP3Player::getUi() const {
    return ui;
}


/*!
 * Method that starts playing current song
 */
void MP3Player::PlaySong() {

    player->setVolume(100);
    player->play();
}

/*!
 * Method that pauses current song
 */
void MP3Player::PauseSong() {
    player->pause();
}

/*!
 * Setter for song_duration
 * @param songDuration : qint64
 */
void MP3Player::setSongDuration(qint64 songDuration) {
    song_duration = songDuration;
}

/*!
 * Updates the playback position if slider moved for fast forward or rewinding the song
 * @param position
 */
void MP3Player::SliderMoved(int position) {
    qint64 new_position = song_duration*position/100;
    player->setPosition(new_position);
}