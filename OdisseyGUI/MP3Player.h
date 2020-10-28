//
// Created by Luis Pedro Morales on 19/10/20.
//
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <iostream>
#include <unistd.h>
#include "ui_mainwindow.h"
#include "OS.h"
using namespace std;

#pragma once
class MP3Player {
private:
    QString main_path;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    Ui::MainWindow * ui;
    qint64 song_duration;
    qint64 current_pos;
    int row;
    OS * os;
public:
    MP3Player(Ui::MainWindow ** ppUi);

    ~MP3Player();

    QMediaPlayer *getPlayer() const;

    qint64 getSongDuration() const;

    QMediaPlaylist *getPlaylist() const;

    void UpdateSlider(qint64 current_time);

    Ui::MainWindow *getUi() const;

    void PlaySong();

    void PauseSong();

    void setSongDuration(qint64 songDuration);

    void SliderMoved(int position);

    void setPlayingTrack(int &row, bool click_on_row);

    int getRow() const;
};


