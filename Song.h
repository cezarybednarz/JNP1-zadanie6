#ifndef SONG_H
#define SONG_H

#include "File.h"
#include "Track.h"

#include <iostream>

// TODO try static registration??

class Song : public Track {
public:
    Song() = default;
    Song(File);
    ~Song() {
        std::cout << "song dtor" << std::endl;
    }
    void play() override;
    std::shared_ptr<Track> newTrack(File) override;
};

#endif // SONG_H
