/*!
 * @brief This file contains a method that reads a csv file that contains the track metadata to obtain a linked list
 * with all the metadata ordered by tracks. It also has a method that return a track linked list paginated.
 *
 * @author Mónica Waterhouse
 * @version 1.0
 *
 */

#include <string>
#include <fstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "OS.h"

#ifndef ODISSEYRADIO_LISTGENERATOR_H
#define ODISSEYRADIO_LISTGENERATOR_H

/*!
 * Method that reads a csv file line by line. The rows represent each one of the tracks and the columns the needed information
 * to create a track object.
 *
 * @return A linked list which nodes' data consist of track object type
 */

LinkedList<Track> *readSmallMetadata(){

    LinkedList<Track> *tracks = new LinkedList<Track>();

    OS * os = OS::GetInstance();
    string small_metadata;
    if (os->isLinux())
        small_metadata = "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/project1_resources/fma_metadata/SmallMetadata.csv";
    else
        small_metadata = "../cmake-build-debug/SmallMetaData.csv";
    std::ifstream sourceFile(small_metadata);

    if(!sourceFile.is_open()){
        throw std::runtime_error("Could not open file");
    }

    std::string line, data, title, genre;

    if(sourceFile.good())
    {
        while(sourceFile >> data){

            int i = 0;

            while(std::getline(sourceFile, line)){

                std::stringstream ss(line); /// Create a stringstream of the current line


                int colIdx = 0; /// Keep track of the current column index

                Track *track = new Track();

                i++;

                while(std::getline(ss, data, ',')){

                    if(colIdx == 0){
                        track->setTrackID(data);
                    }

                    else if(colIdx == 1){
                        track->setTitle(data);
                    }

                    else if(colIdx == 2){
                        track->setArtist(data);
                    }

                    else if(colIdx == 3){
                        track->setAlbum(data );
                    }

                    else if(colIdx ==4){
                        track->setGenre(data);
                    }

                    colIdx++;
                }

                genre = track->getGenre();
                title = track->getTitle();
                bool genreStatus = (genre.find("genre_title") != std::string::npos);

                /// This conditional is used to add only those tracks that have a valid title and genre
                if(genreStatus && title.size()>0 && genre.size()>0){
                    tracks->insertElement(track);
                }

            }
        }
    }
    return tracks;
}

/*!
 * This method paginates the tracks by creating a track linked list in order to safe memory
 * @param index represents the real index of the first track that is currently in the paginated list
 *        to keep track of which tracks must be added and deleted when the scroll bar reaches the top or the bottom
 * @param pageSize represents the amount of tracks that can be added in one page
 * @return a track linked list which size is equivalent to 3 times the size of the page
 */
LinkedList<Track> *paginate(int index, int pageSize){

    LinkedList<Track> *allSongs = readSmallMetadata(); 
    LinkedList<Track> *paginated = new LinkedList<Track>();

    NodeLL<Track> *current = allSongs->getFirst();

    int maximumSize = pageSize*3;

    int i = 0;

    while(paginated->getSize() <= maximumSize && current != nullptr){
        if( i>= index){
            paginated->insertElement(current->getData());
        }
        current = current->getNext();
        i++;
    }

    return paginated;
}


#endif //ODISSEYRADIO_LISTGENERATOR_H
