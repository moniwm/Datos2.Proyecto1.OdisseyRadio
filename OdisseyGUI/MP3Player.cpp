/**
 * @brief Class in charge of providing methods to play, pause, fast-forward/backward the selected song
 * @author Luis Pedro Morales Rodríguez
 */

#include "MP3Player.h"

MP3Player::MP3Player(Ui::MainWindow **ppUi) {
    os = OS::GetInstance();
    player = new QMediaPlayer();
    player->setNotifyInterval(50);
    playlist = new QMediaPlaylist(player);
    if (os->isLinux()) {
        main_path = "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/project1_resources/fma_small/";
        playlist->addMedia(QUrl::fromLocalFile(
                "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/project1_resources/fma_small/000/000002.mp3"));
    } else {
        main_path = "/Users/moniwaterhouse/CLionProjects/fma_small/";
        playlist->addMedia(QUrl::fromLocalFile("/Users/moniwaterhouse/CLionProjects//fma_small/000/000002.mp3"));
    }
    player->setPlaylist(playlist);
    row = 0;
    ui = *ppUi;
    ui->nowPlayingLabel->setText("Food");
    ui->songsList->selectRow(row);
}

MP3Player::~MP3Player() {
    delete player;
    delete playlist;
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

    current_pos = 100 * current_time / song_duration;
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
    qint64 new_position = song_duration * position / 100;
    player->setPosition(new_position);
    cout << player->position() << endl;
}

qint64 MP3Player::getSongDuration() const {
    return song_duration;
}

/*!
 * Sets the QMediaPlayer and the song's metadata displayed in the info window. Function called when a row is double clicked
 */
void MP3Player::setPlayingTrack(int &row, bool click_on_row) {

    QTableWidgetItem *track_id = ui->songsList->item(row, 4);
    QTableWidgetItem *track_tittle = ui->songsList->item(row, 0);

    QString s_track_id = track_id->text();
    QString file_path = main_path;
    file_path.append(s_track_id[0]);
    file_path.append(s_track_id[1]);
    file_path.append(s_track_id[2]);
    file_path.append('/');
    file_path.append(s_track_id);
    file_path.append(".mp3");
    this->row = row;
    QString tittle = track_tittle->text();
    ui->nowPlayingLabel->setText(tittle);
    playlist->addMedia(QUrl::fromLocalFile(file_path));
    if (click_on_row)
        playlist->next();
    ui->songsList->selectRow(row);
}

/*!
 * Row getter
 * @return row : int
 */
int MP3Player::getRow() const {
    return row;
}

QMediaPlaylist *MP3Player::getPlaylist() const {
    return playlist;
}

/*!
 * Restart current track
 */
void MP3Player::RestartSong() {
    player->setPosition(0);
}

/*!
 * Plays previous track in the list view
 */
void MP3Player::PreviousSong(int &row) {
    QTableWidgetItem *track_id = ui->songsList->item(row, 4);
    QTableWidgetItem *track_tittle = ui->songsList->item(row, 0);

    QString s_track_id = track_id->text();
    QString file_path = main_path;
    file_path.append(s_track_id[0]);
    file_path.append(s_track_id[1]);
    file_path.append(s_track_id[2]);
    file_path.append('/');
    file_path.append(s_track_id);
    file_path.append(".mp3");
    this->row = row;
    QString tittle = track_tittle->text();
    ui->nowPlayingLabel->setText(tittle);
    playlist->addMedia(QUrl::fromLocalFile(file_path));
    playlist->next();
    ui->songsList->selectRow(row);
}


