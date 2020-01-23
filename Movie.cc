#include "Movie.h"

#include <iostream>

#include "PlayerException.h"

Movie::Movie(File file) : Track(file) {
    if (!file.getMetaData("title").has_value()) {
        throw FileException("missing title");
    }

    if (!file.getMetaData("year").has_value()) { // TODO check year
        throw FileException("missing year");
    }
}

void Movie::play() {
    std::cout << "Movie [";
    std::cout << file.getMetaData("title").value() << ", ";
    std::cout << file.getMetaData("year").value() << "]: ",
    std::cout << file.getContent();
    std::cout << std::endl;
}

std::shared_ptr<Track> Movie::newTrack(File file) {
    return std::shared_ptr<Track>(new Movie(file));
}
