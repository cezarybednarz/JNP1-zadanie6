#include "Song.h"

#include <iostream>
#include "PlayerException.h"

Song::Song(File file) : Track(file) {
    if (!file.getMetaData("artist").has_value()) {
        throw FileException("missing artist");
    }

    if (!file.getMetaData("title").has_value()) {
        throw FileException("missing title");
    }
}

void Song::play() const {
    std::cout << "Song [";
    std::cout << file.getMetaData("artist").value() << ", ";
    std::cout << file.getMetaData("title").value() << "]: ",
    std::cout << file.getContent();
    std::cout << std::endl;
}

std::shared_ptr<Track> Song::newTrack(File file) {
    return std::shared_ptr<Track>(new Song(file));
}