#include "Song.h"

#include <iostream>

Song::Song(File file) : Track(file) {
    // throw
}

void Song::play() {
    std::cout << "playing song" << std::endl;
}

std::shared_ptr<Track> Song::newTrack(File file) {
    return std::shared_ptr<Track>(new Song(file));
}