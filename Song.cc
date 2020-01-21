#include "Song.h"

#include <iostream>

#include "PlayerException.h"

Song::Song(File file) : Track(file) {
    if (!file.getMetaData("artist").has_value()) {
        throw new FileException();
    }

    if (!file.getMetaData("title").has_value()) {
        throw new FileException();
    }
}

void Song::play() {
    std::cout << "Song [";
    std::cout << file.getMetaData("artist").value() << ", ";
    std::cout << file.getMetaData("title").value() << "]: ",
    std::cout << file.getContent();
    std::cout << std::endl;
}

std::shared_ptr<Track> Song::newTrack(File file) {
    return std::shared_ptr<Track>(new Song(file));
}