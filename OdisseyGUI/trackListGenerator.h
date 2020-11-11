#include <string>
#include <fstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "OS.h"

#ifndef ODISSEYRADIO_LISTGENERATOR_H
#define ODISSEYRADIO_LISTGENERATOR_H

LinkedList<Track> *readSmallMetadata(){

    LinkedList<Track> *tracks = new LinkedList<Track>();


    //std::ifstream sourceFile("../cmake-build-debug/SmallMetaData.csv");
    //string source = "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/project1_resources/fma_metadata/SmallMetadata.csv";
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

                // Create a stringstream of the current line
                std::stringstream ss(line);

                // Keep track of the current column index

                // Extract each integer
                int colIdx = 0;

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

                if(genreStatus && title.size()>0 && genre.size()>0){
                    tracks->insertElement(track);
                }



            }
        }
    }
    return tracks;
}

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