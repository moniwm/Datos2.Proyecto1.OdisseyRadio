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

    void on_loadBtn_clicked();

    void on_allBtn_stateChanged(int arg1);

    void on_paginateBtn_clicked();

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 duration);

    void resizeEvent(QResizeEvent *event);

    void on_songControl_sliderPressed();

    void on_songControl_sliderReleased();


private:

    bool is_playing, is_slider_pressed;

    MP3Player * mp3_player;

    DurationSubject * duration_subject;

    Ui::MainWindow *ui;

    int SliderPos(int time);

    QString SecondsToMinutes(qint64 seconds);

};
