//
// Created by Luis Pedro Morales on 20/10/20.
//
#include <QtGlobal>
#include <list>
#include "MP3Player.h"
#pragma once

/*!
 * Class that implements an observer pattern design to notify MP3Player objects that the duration of song has changed
 */
class DurationSubject {
private:
    qint64 duration;
    list< MP3Player *> list_observer;

public:
    DurationSubject();
    ~DurationSubject();

    void Attach(MP3Player ** pp_mp3_player);

    void Detach(MP3Player ** pp_mp3_player);

    void Notify(qint64 duration);

};
