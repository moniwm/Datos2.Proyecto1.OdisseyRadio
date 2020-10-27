#include <string>
#include <fstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "../Metadata/tracks.h"
#include "../Metadata/LinkedList.h"

#ifndef ODISSEYRADIO_LISTGENERATOR_H
#define ODISSEYRADIO_LISTGENERATOR_H



LinkedList<Track> *readSmallMetadata(){

    LinkedList<Track> *tracks = new LinkedList<Track>();


    std::ifstream sourceFile("../cmake-build-debug/SmallMetaData.csv");

    if(!sourceFile.is_open()){
        throw std::runtime_error("Could not open file");
    }

    std::string line, data;

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
                        std::cout << data <<" ";
                    }

                    else if(colIdx == 1){
                        track->setAlbum(data);
                        std::cout << data <<" ";
                    }

                    else if(colIdx == 2){
                        track->setArtist(data);
                        std::cout << data <<" ";
                    }

                    else if(colIdx == 3){
                        track->setGenre(data );
                        std::cout << data <<" ";
                    }

                    else if(colIdx ==4){
                        track->setTitle(data);
                        std::cout << data <<" ";
                    }

                    std::cout <<"\n";
                    colIdx++;

                }

                tracks->insertElement(track);


            }
        }
    }

    NodeLL<Track> *current = tracks->getFirst();

    for(int i  = 0; i < tracks->getSize(); i++){
        std::cout << current->getData()->getTrackID() << "\n";
    }

    return tracks;


}

#endif //ODISSEYRADIO_LISTGENERATOR_H
