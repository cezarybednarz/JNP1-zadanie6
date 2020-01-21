#ifndef SONG_H
#define SONG_H

#include "File.h"
#include "Track.h"

// TODO try static registration??

class Song : public Track {
public:
    Song() = default;
    Song(File);
    void play() override;
    std::shared_ptr<Track> newTrack(File) override;
};

#endif // SONG_H