/**
 * @brief This file contains the track class which obtains the metadata from the raw_tracks.csv file and
 * obtains each track metadata to fill the song list view.
 *
 * @author Monica Waterhouse Montoya
 * @since 10/22/2020
 */

#include "tracks.h"

Track::Track() {
    this->length = "00:30";
}

Track::~Track() {
    delete this;
}

void Track::setAlbum(std::string album) {
    this->album = album;
}

void Track::setArtist(std::string artist) {
    this->artist = artist;
}

void Track::setGenre(std::string genre) {
    this->genre = genre;
}

void Track::setTitle(std::string title) {
    this->title = title;
}

void Track::setTrackID(std::string trackID) {
    this->trackID = trackID;
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

std::string Track::getTrackID() {
    return this->trackID;
}