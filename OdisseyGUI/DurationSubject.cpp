//
// Created by Luis Pedro Morales on 20/10/20.
//

#include "DurationSubject.h"

/*!
 * Subscription method
 * @param pp_mp3_player
 */
void DurationSubject::Attach(MP3Player **pp_mp3_player) {
    list_observer.push_back(*pp_mp3_player);
}

/*!
 * Unsubscription method
 * @param pp_mp3_player
 */
void DurationSubject::Detach(MP3Player **pp_mp3_player) {
    list_observer.push_back(*pp_mp3_player);
}

void DurationSubject::Notify(qint64 duration) {
    list<MP3Player *>::iterator iterator = list_observer.begin();
    while( iterator != list_observer.end()){
        (*iterator)->setSongDuration(duration);
        ++iterator;
    }
}

DurationSubject::~DurationSubject() {
    delete this;
}

DurationSubject::DurationSubject() {

}
