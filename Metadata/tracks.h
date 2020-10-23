/**
 * @brief This file contains the track class which obtains the metadata from the raw_tracks.csv file and
 * obtains each track metadata to fill the song list view.
 *
 * @author Monica Waterhouse Montoya
 * @since 10/22/2020
 */

#ifndef ODISSEYRADIO_TRACKS_H
#define ODISSEYRADIO_TRACKS_H

#include <iostream>
#include <string>
using namespace std;

class Track {

private:
    std::string album;
    std::string title;
    std::string artist;
    std::string length;
    std::string genre;

public:

    Track(std::string album, std::string title, std::string artist, std::string length, std::string genre);
    ~Track();

    std::string getAlbum();
    std::string getTitle();
    std::string getArtist();
    std::string getLength();
    std::string getGenre();

};


#endif //ODISSEYRADIO_TRACKS_H
