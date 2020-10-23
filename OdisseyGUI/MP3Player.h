//
// Created by Luis Pedro Morales on 19/10/20.
//
#include <QString>
#include <QMediaPlayer>
#include <iostream>
#include "ui_mainwindow.h"
using namespace std;

#pragma once
class MP3Player {
private:
    QString file_path;
    QMediaPlayer *player;
    Ui::MainWindow * ui;
    qint64 song_duration;
    qint64 current_pos;
public:
    MP3Player(Ui::MainWindow ** ppUi);

    ~MP3Player();

    QMediaPlayer *getPlayer() const;

    qint64 getSongDuration() const;

    void UpdateSlider(qint64 current_time);

    Ui::MainWindow *getUi() const;

    void PlaySong();

    void PauseSong();

    void setSongDuration(qint64 songDuration);

    void SliderMoved(int position);
};


