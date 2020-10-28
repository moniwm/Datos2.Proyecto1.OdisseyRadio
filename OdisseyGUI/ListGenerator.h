#include <string>
#include <fstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

#ifndef ODISSEYRADIO_LISTGENERATOR_H
#define ODISSEYRADIO_LISTGENERATOR_H


LinkedList<Track> *readSmallMetadata(){

    LinkedList<Track> *tracks = new LinkedList<Track>();


    std::ifstream sourceFile("../cmake-build-debug/SmallMetaData.csv");
    //std::ifstream sourceFile("/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/project1_resources/fma_metadata/SmallMetadata.csv");

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

                tracks->insertElement(track);

            }
        }
    }

    tracks->remove(0);

    return tracks;


}

#endif //ODISSEYRADIO_LISTGENERATOR_H
