/**
  * @brief Source file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */
#include "mainwindow.h"
#include "ListGenerator.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Ui::MainWindow **ppUi = &ui;

    os = OS::GetInstance();

    track_list = readSmallMetadata();

    mem_usage = new MemoryUsage();

    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint); // Set borderless window

    ///This block of code sets the width for each one of the columns of the table

    ui->songsList->setColumnWidth(0, 275);
    ui->songsList->setColumnWidth(1, 163);
    ui->songsList->setColumnWidth(2, 100);
    ui->songsList->setColumnWidth(3, 100);

    extraRows = 0; ///This variable contains the extra amount of rows to be added depending on the window size

    mp3_player = new MP3Player(ppUi);
    MP3Player **pp_mp3_player = &mp3_player;

    init_mframe_posy = ui->memory_frame->pos().y();

    duration_subject = new DurationSubject();
    duration_subject->Attach(pp_mp3_player);

    is_playing = is_slider_pressed = false;

    connect(mp3_player->getPlayer(), SIGNAL(positionChanged(qint64)), this, SLOT(on_positionChanged(qint64)));
    connect(mp3_player->getPlayer(), SIGNAL(durationChanged(qint64)), this, SLOT(on_durationChanged(qint64)));

    ui->songsList->hideColumn(4);

    this->loadTracks();

    ui->songsList->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->songsList, SIGNAL(doubleClicked(const QModelIndex &)), this,
            SLOT(on_sectionDoubleClicked(QModelIndex)));

    NodeLL<Track> *first = track_list->getFirst();
    current_artist = QString::fromStdString(first->getData()->getArtist());
    current_title = QString::fromStdString(first->getData()->getTitle());
    current_length = QString::fromStdString(first->getData()->getLength());
    current_genre = QString::fromStdString(first->getData()->getGenre());

    allBtn_uncheckedManually = true;

    SetPlayBtn();
    SetPreviousBtn();
    SetNextBtn();
    UpdateMemoryPB();
    getArtistList(track_list);
    checkAllArtists();

    ui->allBtn->setCheckState(Qt::Checked);

    isInitDone = true;


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_durationChanged(qint64 duration) {
    duration_subject->Notify(duration);
}

void MainWindow::on_playBtn_clicked() {

    if (is_playing) {

        SetPlayBtn();

        mp3_player->PauseSong();
    } else {

        SetPauseBtn();

        int position = ui->songControl->value();
        mp3_player->SliderMoved(position);

        mp3_player->PlaySong();

    }
    is_playing = !is_playing;
}

void MainWindow::on_infoBtn_clicked() {
    information = new Information(this);
    information->getInformation(this->current_title, this->current_genre, this->current_artist, this->current_length);
    information->show();

}


void MainWindow::on_paginateBtn_clicked() {
    UpdateMemoryPB(); //updates memory progress bar
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

    manageTableSize();
}


/*!
 * Private slot. Updates song's slider position if it isn't pressed
 * @param position : qint64
 */
void MainWindow::on_positionChanged(qint64 position) {
    if (!is_slider_pressed)
        mp3_player->UpdateSlider(position);

    if (position == mp3_player->getSongDuration()) {
        int new_row = mp3_player->getRow();
        new_row++;
        mp3_player->setPlayingTrack(new_row, false);
        SetInfoWin(new_row);
    }
    ui->lengthLabel->setText(SecondsToMinutes(position / 1000));
}

/*!
 * Sets flag to disable movement of the slider
 */
void MainWindow::on_songControl_sliderPressed() {
    is_slider_pressed = true;
}

/*!
 * Updates the playback position in the song when the slider is released
 */
void MainWindow::on_songControl_sliderReleased() {
    is_slider_pressed = false;
    int position = ui->songControl->value();
    mp3_player->SliderMoved(position);
}

/*!
 * Parse seconds to minute:seconds QString format
 * @param seconds
 * @return
 */
QString MainWindow::SecondsToMinutes(qint64 seconds) {
    int sec = seconds;
    QString mn = QString::number((sec) / 60);
    int _tmp_mn = mn.toInt() * 60;
    QString sc = QString::number((seconds - _tmp_mn) % 60);

    return (mn.length() == 1 ? "0" + mn : mn) + ":" + (sc.length() == 1 ? "0" + sc : sc);
}

/**
 * Updates the memory progress bar indicating the percentage of resident set size memory related with the max rss
 */
void MainWindow::UpdateMemoryPB() {
    mem_usage->MemUsage(vm, rss, max_rss);
    int int_rss = rss;
    int val = rss / max_rss * 100;
    ui->memoryPB->setValue(val);
    QString text = "Memory usage: ";
    text.append(QString::fromUtf8(to_string(int_rss).c_str()));
    text.append(" MB");
    ui->memoryUsageLabel->setText(text);
}

void MainWindow::loadTracks() {

    ui->songsList->setRowCount(track_list->getSize());

    NodeLL<Track> *current = track_list->getFirst();
    QString title;
    QString length;
    QString genre;
    QString artist;
    QString trackID;

    for (int i = 0; i < track_list->getSize(); i++) {
        title = QString::fromStdString(current->getData()->getTitle());
        length = QString::fromStdString(current->getData()->getLength());
        genre = QString::fromStdString(current->getData()->getGenre()).mid(16);
        artist = QString::fromStdString(current->getData()->getArtist());
        trackID = QString::fromStdString(current->getData()->getTrackID());


        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                ui->songsList->setItem(i, j, new QTableWidgetItem(title));
            } else if (j == 1) {
                ui->songsList->setItem(i, j, new QTableWidgetItem(artist));
            } else if (j == 2) {
                ui->songsList->setItem(i, j, new QTableWidgetItem(length));
            } else if (j == 3) {
                ui->songsList->setItem(i, j, new QTableWidgetItem(genre));
            } else {
                ui->songsList->setItem(i, j, new QTableWidgetItem(trackID));
            }

        }

        current = current->getNext();
    }

}

/*!
 * When a row is double clicked, calls method that sets the new playing track
 * @param index
 */
void MainWindow::on_sectionDoubleClicked(const QModelIndex &index) {
    int cell_row;
    if (index.isValid()) {
        cell_row = index.row();
    }
    if (!is_playing)
        on_playBtn_clicked();
    mp3_player->setPlayingTrack(cell_row, true);
    SetInfoWin(cell_row);

}

/*!
 * sets icon for play button
 */
void MainWindow::SetPlayBtn() {
    if (os->isLinux()) {
        QPixmap play(
                "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/play.png");
        QIcon playIcon(play);
        ui->playBtn->setIcon(playIcon);
    } else {
        QPixmap play("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/play.png");
        QIcon playIcon(play);
        ui->playBtn->setIcon(playIcon);
    }
}

/*!
 * sets icon for play button
 */
void MainWindow::SetPauseBtn() {
    if (os->isLinux()) {
        QPixmap pause(
                "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/pause.png");
        QIcon pauseIcon(pause);
        ui->playBtn->setIcon(pauseIcon);
    } else {
        QPixmap pause("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/pause.png");
        QIcon pauseIcon(pause);
        ui->playBtn->setIcon(pauseIcon);
    }
}

void MainWindow::SetNextBtn() {
    if (os->isLinux()) {
        QPixmap next(
                "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/next.png");
        QIcon nextIcon(next);
        ui->nextBtn->setIcon(nextIcon);
    } else {
        QPixmap next("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/next.png");
        QIcon nextIcon(next);
        ui->nextBtn->setIcon(nextIcon);
    }
}

void MainWindow::SetPreviousBtn() {
    if (os->isLinux()) {
        QPixmap previous(
                "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Project 1/OdisseyGUI/images/previous.png");
        QIcon previousIcon(previous);
        ui->previousBtn->setIcon(previousIcon);
    } else {
        QPixmap previous("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/previous.png");
        QIcon previousIcon(previous);
        ui->previousBtn->setIcon(previousIcon);
    }
}


void MainWindow::on_nextBtn_clicked()
{
    if (!is_playing)
        on_playBtn_clicked();
    int new_row = mp3_player->getRow();
    new_row++;
    mp3_player->setPlayingTrack(new_row, true);
    ui->songsList->selectRow(new_row);
    SetInfoWin(new_row);
}

void MainWindow::on_previousBtn_clicked()
{
    if (mp3_player->getPlayer()->position() < 1000){
        int new_row = mp3_player->getRow();
        if (new_row > 0){
            new_row--;
            mp3_player->PreviousSong(new_row);
        }else
            mp3_player->RestartSong();
        SetInfoWin(new_row);
    }
    else
        mp3_player->RestartSong();

}

/*!
 * Sets info window with the metadata of current track
 * @param cell_row : int
 */
void MainWindow::SetInfoWin(int &cell_row) {
    QTableWidgetItem *track_title = ui->songsList->item(cell_row, 0);
    QTableWidgetItem *track_artist = ui->songsList->item(cell_row, 1);
    QTableWidgetItem *track_length = ui->songsList->item(cell_row, 2);
    QTableWidgetItem *track_genre = ui->songsList->item(cell_row, 3);

    current_title = track_title->text();
    current_artist = track_artist->text();
    current_length = track_length->text();
    current_genre = track_genre->text();
}

void MainWindow::getArtistList(LinkedList<Track> *allTracks) {
    NodeLL<Track> *current = allTracks->getFirst();
    std::string current_artist;

    QString artist_name;

    for(int i = 0; i < allTracks->getSize(); i++){
        current_artist = current->getData()->getArtist();

        if(std::find(artist_list.begin(), artist_list.end(), current_artist) == artist_list.end()){
            artist_list.push_back(current_artist);
            artist_name = QString::fromStdString(current_artist);
            QListWidgetItem *item = new QListWidgetItem(artist_name, ui->artist_listWidget);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
            item->setCheckState(Qt::Unchecked);

        }

        current = current->getNext();

    }

}

void MainWindow::on_allBtn_stateChanged(int arg1)
{
    if(ui->allBtn->isChecked()){
        allBtnPressed = true;
        track_list = readSmallMetadata();
        loadTracks();
        checkAllArtists();
        allBtn_uncheckedManually = true;

    }

    else{
        allBtnPressed = false;
        if(allBtn_uncheckedManually){
            uncheckAllArtists();
            allBtn_uncheckedManually = true;
            ui->songsList->setRowCount(page_size);

            manageTableSize();
        }

    }

}


void MainWindow::checkAllArtists() {

    for(int i = 0; i < artist_list.size(); i++){
        ui->artist_listWidget->item(i)->setCheckState(Qt::Checked);
    }
}

void MainWindow::uncheckAllArtists() {
    for(int i = 0; i < artist_list.size(); i++){
        ui->artist_listWidget->item(i)->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_artist_listWidget_itemChanged(QListWidgetItem *item)
{

    int state = item->checkState();
    std::string artist_name = item->text().toStdString();

    if(isInitDone){

        if(state == 0){
            allBtn_uncheckedManually = false;
            ui->allBtn->setCheckState(Qt::Unchecked);

            if(allBtn_uncheckedManually){
                track_list->clear();
            }
            else{
                removeTrack(artist_name);
            }

            loadTracks();

            allBtnPressed = false;

        }


        else{
            if(!allBtnPressed){
                addTracks(artist_name);
                loadTracks();
            }

        }
    }


}

void MainWindow::removeTrack(std::string artist_name) {

    NodeLL<Track> *current = track_list->getFirst();
    NodeLL<Track> *temp;
    std::string artist;

    while(current != nullptr){
        artist = current->getData()->getArtist();
        temp = current->getNext();

        if(artist == artist_name){
            track_list->remove(current);
        }

        current = temp;
    }

}

void MainWindow::addTracks(std::string artist_name) {
    LinkedList<Track> *allTracks = readSmallMetadata();
    std::string refArtist;

    NodeLL<Track> *current = allTracks->getFirst();

    for(int i = 0; i < allTracks->getSize(); i++){
        refArtist = current->getData()->getArtist();

        if(refArtist == artist_name){
            track_list->insertElement(current->getData());
        }

        current = current->getNext();
    }

}

void MainWindow::manageTableSize() {
    heightDifference = MainWindow::size().height() - minimumHeight();
    extraRows = heightDifference / rowHeight;
    page_size = minimumRows + extraRows;

    ui->songsList->setFixedHeight(minimumTableHeight + heightDifference);

    ui->memory_frame->move(0, init_mframe_posy + heightDifference);

    ui->artist_listWidget->setFixedHeight(minimumListHeight + heightDifference);

    //ui->songsList->setRowCount(page_size);
}

