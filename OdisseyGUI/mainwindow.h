/**
  * @brief Header file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */

#pragma once

#include <QMainWindow>
#include <QFileInfo>
#include <QFileDialog>

#include "MP3Player.h"
#include "DurationSubject.h"
#include "ui_mainwindow.h"
#include "MemoryUsage.h"
#include "OS.h"
#include "../Metadata/LinkedList.h"
#include "../Metadata/tracks.h"
#include "information.h"
#include "vector"


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_playBtn_clicked();

    void on_infoBtn_clicked();

    void on_paginateBtn_clicked();

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 duration);

    void resizeEvent(QResizeEvent *event);

    void on_songControl_sliderPressed();

    void on_songControl_sliderReleased();

    void on_sectionDoubleClicked(const QModelIndex &index);
    
    void on_nextBtn_clicked();

    void on_previousBtn_clicked();

    void on_allBtn_stateChanged(int arg1);

    void on_artist_listWidget_itemChanged(QListWidgetItem *item);

    void printScrollBarValue();

private:
    MemoryUsage * mem_usage;
    double vm, rss, max_rss;

    Information *information;

    int const rowHeight = 31; /// Constant variable that stores the height of the table rows
    int const minimumRows = 16; /// Minimum amount of rows without scrolling
    int const minimumTableHeight = 500;
    int const minimumListHeight = 361;

    int extraRows;
    int heightDifference;
    int page_size;

    bool is_playing, is_slider_pressed;

    bool isInitDone = false;
    bool allBtnPressed = true;

    MP3Player * mp3_player;

    LinkedList<Track> *track_list;
    std::vector<std::string> artist_list;

    DurationSubject * duration_subject;

    Ui::MainWindow *ui;

    int SliderPos(int time);

    QString SecondsToMinutes(qint64 seconds);

    void UpdateMemoryPB();

    void loadTracks();

    OS *os;

    QString current_title;
    QString current_genre;
    QString current_artist;
    QString current_length;

    int init_mframe_posy;

    bool allBtn_uncheckedManually;

    void SetPlayBtn();

    void SetPauseBtn();

    void SetPreviousBtn();

    void SetNextBtn();

    void SetInfoWin(int &cell_row);

    void getArtistList(LinkedList<Track> *allTracks);

    void checkAllArtists();

    void uncheckAllArtists();

    void removeTrack(std::string artist_name);

    void addTracks(std::string artist_name);

    void manageTableSize();

    void adjustTableSize();

    double readMemory();


};
