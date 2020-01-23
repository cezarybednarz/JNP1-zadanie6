#ifndef SONG_H
#define SONG_H

#include "File.h"
#include "Track.h"

class Song : public Track {
public:
    Song() = default;
    Song(File);
    ~Song() = default;
    void play() const override;
    std::shared_ptr<Track> newTrack(File) override;
};

#endif // SONG_H
