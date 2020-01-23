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

std::string Movie::decode(std::string content) {
    for (char &c : content) {
        if (c >= 'A' && c <= 'Z') {
            c -= 'A';
            c += 13;
            c %= 26;
            c += 'A';
        } else if (c >= 'a' && c <= 'z') {
            c -= 'a';
            c += 13;
            c %= 26;
            c += 'a';
        }
    }
    
    return content;
}

void Movie::play() {
    std::cout << "Movie [";
    std::cout << file.getMetaData("title").value() << ", ";
    std::cout << file.getMetaData("year").value() << "]: ",
    std::cout << decode(file.getContent());
    std::cout << std::endl;
}

std::shared_ptr<Track> Movie::newTrack(File file) {
    return std::shared_ptr<Track>(new Movie(file));
}
