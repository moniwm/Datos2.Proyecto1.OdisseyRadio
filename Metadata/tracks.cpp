/**
 * @brief This file contains the track class which obtains the metadata from the raw_tracks.csv file and
 * obtains each track metadata to fill the song list view.
 *
 * @author Monica Waterhouse Montoya
 * @since 10/22/2020
 */

#include "tracks.h"

Track::Track(std::string album, std::string title, std::string artist, std::string length, std::string genre) {

    this->album = album;
    this->title = title;
    this->artist = artist;
    this->length = length;
    this->genre = genre;

}

Track::~Track() {
    delete this;
}

std::string Track::getAlbum() {
    return this->album;
}

std::string Track::getArtist() {
    return this->artist;
}

std::string Track::getGenre() {
    return this->genre;
}

std::string Track::getLength() {
    return this->length;
}

std::string Track::getTitle() {
    return this->title;
}