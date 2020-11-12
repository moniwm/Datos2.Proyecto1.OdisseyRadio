/**
  * @brief Source file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya, Luis Pedro Morales Rodríguez
  * @since October 9th, 2020
  *
  */
#include "mainwindow.h"
#include "trackListGenerator.h"
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    Ui::MainWindow **ppUi = &ui;
    os = OS::GetInstance(); // Is used to detect in which operating system the program is currently running

    // -------------------------------- Code related to GUI elements modifications ----------------------------

    ui->songsList->setColumnWidth(0, 275);
    ui->songsList->setColumnWidth(1, 163);
    ui->songsList->setColumnWidth(2, 100);
    ui->songsList->setColumnWidth(3, 100);

    QPixmap logo("/Users/moniwaterhouse/CLionProjects/OdisseyRadio/OdisseyGUI/images/Logo.png");
    ui->nameLabel->setPixmap(logo);

    ui->songsList->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->songsList->hideColumn(4); // This row contains the track id and is used to access the mp3 file related to that track

    init_mframe_posy = ui->memory_frame->pos().y(); // The initial position of the frame that contains the memory usage information

    // -------------------------------- Variables initialization ----------------------------------------------

    track_list = readSmallMetadata(); // Obtains the list with all the tracks available in the csv file

    mp3_player = new MP3Player(ppUi);
    MP3Player **pp_mp3_player = &mp3_player;
    duration_subject = new DurationSubject();
    duration_subject->Attach(pp_mp3_player);
    is_playing = is_slider_pressed = false;

    firstElementIndex = 0;
    maxTrackSize = track_list->getSize();
    maxMemory = readMemory()/1024.0;

    NodeLL<Track> *first = track_list->getFirst();
    current_artist = QString::fromStdString(first->getData()->getArtist());
    current_title = QString::fromStdString(first->getData()->getTitle());
    current_length = QString::fromStdString(first->getData()->getLength());
    current_genre = QString::fromStdString(first->getData()->getGenre()).mid(16);

    this->loadTracks();

    allBtn_uncheckedManually = true;
    paginated = false;
    ui->allBtn->setCheckState(Qt::Checked);

    SetPlayBtn();
    SetPreviousBtn();
    SetNextBtn();
    getArtistList(track_list);
    checkAllArtists();
    UpdateMemoryPB();

    // ---------------------------------------- Signals and slots ----------------------------------------------------
    connect(mp3_player->getPlayer(), SIGNAL(positionChanged(qint64)), this,
            SLOT(on_positionChanged(qint64)));
    connect(mp3_player->getPlayer(), SIGNAL(durationChanged(qint64)), this,
            SLOT(on_durationChanged(qint64)));
    connect(ui->songsList, SIGNAL(doubleClicked(const QModelIndex &)), this,
            SLOT(on_sectionDoubleClicked(QModelIndex)));
    connect(ui->songsList->verticalScrollBar(), SIGNAL(valueChanged(int)), this,
            SLOT(infiniteScroll()));

    isInitDone = true;
}

MainWindow::~MainWindow() {
    delete ui;
}


// --------------------------------------- Play songs related methods ----------------------------------------------

/*!
 * Notifies when the fast forward or backward the song that is now playing
 * @param duration
 */
void MainWindow::on_durationChanged(qint64 duration) {
    duration_subject->Notify(duration);
}

/*!
 * Controls when to play or pause the song that is currently selected
 */
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

/*!
 * Opens the information window
 */
void MainWindow::on_infoBtn_clicked() {
    information = new Information(this);
    information->getInformation(this->current_title, this->current_genre, this->current_artist, this->current_length);
    information->show();

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

/*!
 * Sets icon for next song button
 */
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

/*!
 * Sets icon for previous song button
 */
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

/*!
 * Plays next song in the list view
 */
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

/*!
 * Plays previous song in the list view
 */
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

// ------------------------------------- Artist menu ----------------------------------------

/*!
 * Reads the track list with all tracks loaded and takes the name of each one of the artist in order to display
 * them in a menu and the user can add or remove tracks from the list.
 *
 * @param allTracks is the linked list that contains all the tracks
 */
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

/*!
 * Detects when the state of the all artist button has change
 * @param arg1
 */
void MainWindow::on_allBtn_stateChanged(int arg1)
{
    if(ui->allBtn->isChecked()){
        firstElementIndex = 0;
        allBtnPressed = true;
        track_list = readSmallMetadata();
        loadTracks();
        checkAllArtists();
        allBtn_uncheckedManually = true;

    }

    else{
        allBtnPressed = false;
        ui->paginateBtn->setChecked(false);
        paginated = false;
        if(allBtn_uncheckedManually){
            track_list->clear();
            uncheckAllArtists();
            ui->songsList->setRowCount(page_size);
            manageTableSize();

        }

    }

}

/*!
 * Checks all the artists names' boxes
 */
void MainWindow::checkAllArtists() {

    for(int i = 0; i < artist_list.size(); i++){
        ui->artist_listWidget->item(i)->setCheckState(Qt::Checked);
    }
}

/*!
 * Unchecks all the artists names' boxes
 */
void MainWindow::uncheckAllArtists() {
    for(int i = 0; i < artist_list.size(); i++){
        ui->artist_listWidget->item(i)->setCheckState(Qt::Unchecked);
    }
}

/*!
 * Detects when a the check box of an artist has changed
 * @param item the artist which check box state changed
 */
void MainWindow::on_artist_listWidget_itemChanged(QListWidgetItem *item)
{

    int state = item->checkState();
    std::string artist_name = item->text().toStdString();

    if(paginated == true){ // This conditional avoids unwanted behavior when paginating
        track_list = readSmallMetadata();
        paginated = false;
    }

    if(isInitDone){ // This conditional is used to make sure the next code of block is run only when the program is completely set

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


// -------------------------------------- Memory management ---------------------------------

/*!
 * Control the pagination of the track linked list
 */
void MainWindow::on_paginateBtn_clicked() {
    if(ui->allBtn->isChecked()){
        if(ui->paginateBtn->isChecked()){
            track_list = paginate(firstElementIndex, page_size);
            paginated = true;
        }

        else{
            paginated = false;
            track_list = readSmallMetadata();
        }

        loadTracks();
    }

    else{
        ui->paginateBtn->setChecked(false);
    }

    UpdateMemoryPB(); //updates memory progress bar

}

/*!
 * Updates the memory progress bar indicating the percentage of resident set size memory related with the max rss
 */
void MainWindow::UpdateMemoryPB() {

    float memoryUsed  = readMemory() / 1024.00;
    int val = memoryUsed / maxMemory * 100;
    ui->memoryPB->setValue(val);
    QString text = "Memory usage: ";
    text.append(QString::fromUtf8(to_string(memoryUsed).c_str()));
    text.append(" KB");
    ui->memoryUsageLabel->setText(text);
}

/*!
 * Reads the memory consumed by the track linked list
 * @return
 */
double MainWindow::readMemory() {
    return sizeof(*track_list->getFirst()->getData())*track_list->getSize();
}

void MainWindow::infiniteScroll() {
    if(ui->paginateBtn->isChecked()){
        int sb_position = ui->songsList->verticalScrollBar()->value();
        int maximum_pos = ui->songsList->verticalScrollBar()->maximum();
        if(sb_position == maximum_pos && firstElementIndex < maxTrackSize-page_size){
            firstElementIndex = firstElementIndex + page_size;
            track_list = paginate(firstElementIndex, page_size);
            loadTracks();
            ui->songsList->verticalScrollBar()->setValue(int(2*maximum_pos/3));
        }
        else if(sb_position == 0 && firstElementIndex-page_size >= 0){
            firstElementIndex = firstElementIndex - page_size;
            track_list = paginate(firstElementIndex, page_size);
            loadTracks();
            ui->songsList->verticalScrollBar()->setValue(maximum_pos-int(2*maximum_pos/3));
        }
    }
}


// --------------------------------- Track list management ----------------------------------

/*!
 * This method calculates the amount of rows visible to the client without scrolling the list
 * @param event
 */
void MainWindow::resizeEvent(QResizeEvent *event) {

    manageTableSize();
    if(ui->paginateBtn->isChecked()){
        track_list = paginate(firstElementIndex, page_size);
        loadTracks();
    }
}

/*!
 * Fills the table view with all the information from the track linked list
 */
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

    UpdateMemoryPB();
    manageTableSize();


}

/*!
 * Removes tracks when an artist check box is uncheked
 * @param artist_name this variable is use as a key to know which tracks has to be removed from the linked list
 */
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

/*!
 * Adds tracks when an artist check box is uncheked
 * @param artist_name artist_name this variable is use as a key to know which tracks has to be added to the linked list
 */
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

/*!
 * Controls the table size and row count when the main window is resized
 */
void MainWindow::manageTableSize() {
    heightDifference = MainWindow::size().height() - minimumHeight();
    extraRows = heightDifference / rowHeight;
    page_size = minimumRows + extraRows;

    ui->songsList->setFixedHeight(minimumTableHeight + heightDifference);

    ui->memory_frame->move(0, init_mframe_posy + heightDifference);

    ui->artist_listWidget->setFixedHeight(minimumListHeight + heightDifference);

    if(track_list->getSize() < page_size){
        ui->songsList->setRowCount(page_size);
    }

}