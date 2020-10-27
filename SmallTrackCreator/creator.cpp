#include <string>
#include <fstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "../Metadata/tracks.h"
#include "../Metadata/LinkedList.h"
#include <vector>

/**
 * @brief This file is use to create a new CSV file from an existing CSV file. In this case, the idea of using this
 * code is to take the raw_track.csv file found in the fma_metadata directory and create a new one taking in
 * consideration only the required info: title, trackid, album, genre and length. Also, it is design to take only
 * the metadata from the songs that exists in the fma_small dirctory.
 *
 * @author Mónica Waterhouse
 *
 * @link https://github.com/mdeff/fma
 */

LinkedList<Track> *readTracksFile(std::string rawTracksPath){

    LinkedList<Track> *tracks = new LinkedList<Track>();

    bool add = true;

    std::ifstream sourceFile(rawTracksPath);

    if(!sourceFile.is_open()){
        throw std::runtime_error("Could not open file");
    }

    std::string line, data, temp, colname;

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
                        if(data.size() < 6){
                            int dataSize = data.size();
                            for (int i = 0; i < 6 - dataSize; i++){
                                data.insert(0, "0", 1);
                            }
                        }
                        track->setTrackID(data);
                    }

                    else if(colIdx == 2){
                        track->setAlbum(data);
                    }

                    else if(colIdx == 5){
                        track->setArtist(data);
                    }

                    else if(colIdx == 28){
                        track->setGenre(data );
                    }

                    else if(colIdx == 39){
                        track->setTitle(data);
                    }

                    colIdx++;

                }

                tracks->insertElement(track);


            }
        }
    }

    return tracks;


}

std::vector<std::string> readSmallTracks(std::string filename){

    std::vector<std::string> songs;

    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname, data;

    // Read the column names
    if(myFile.good())
    {
        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            // Keep track of the current column index
            int colIdx = 0;

            // Extract each integer
            while(ss >> data){

                songs.push_back(data.substr(4,6));

                // Increment the column index
                colIdx++;
            }
        }

    }

    // Close file
    myFile.close();

    return songs;

}

int writeNewCSV(){

    LinkedList<Track> *songs = readTracksFile("/Users/moniwaterhouse/CLionProjects/fma_metadata/raw_tracks.csv");
    std::vector<std::string> tracks = readSmallTracks("/Users/moniwaterhouse/CLionProjects/fma_small/checksums.csv");


    std::ofstream smallTracks("SmallMetadata.csv"); /// Creates a csv file

    /// Set the column titles of the csv file

    smallTracks << "TrackID,";
    smallTracks << "Title,";
    smallTracks << "Artist,";
    smallTracks << "Album,";
    smallTracks << "Genre,";
    smallTracks << "Length";
    smallTracks << "\n";

    NodeLL<Track> *current = songs->getFirst();

    int k = 0;

    while(k < tracks.size()){

        std::string track_to_compare = tracks.at(k);

        for (int i = 0; i < songs->getSize(); i++){

            std::string trackID = current->getData()->getTrackID();
            std::string title = current->getData()->getTitle();
            int trackID_size = trackID.size();

            if(trackID.size() < 6){
                for(int j = 0; j < 6 - trackID_size; j++){
                    trackID.insert(0, "0", 1);
                }
            }

            if(trackID == tracks.at(k)){

                smallTracks << current->getData()->getTrackID();
                smallTracks << ",";
                smallTracks << current->getData()->getTitle();
                smallTracks << ",";
                smallTracks << current->getData()->getArtist();
                smallTracks << ",";
                smallTracks << current->getData()->getAlbum();
                smallTracks << ",";
                smallTracks << current->getData()->getGenre();
                smallTracks << ",";
                smallTracks << current->getData()->getLength();

                smallTracks <<"\n";
                current = current->getNext();
                break;
            }

            current = current->getNext();
        }

        k++;
    }



    smallTracks.close();

}

/*int main() {
    writeNewCSV();
    return 0;
}*/