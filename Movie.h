#ifndef MOVIE_H
#define MOVIE_H

#include "File.h"
#include "Track.h"

// TODO try static registration??

class Movie : public Track {
public:
    Movie() = default;
    Movie(File);
    void play() override;
    std::shared_ptr<Track> newTrack(File) override;
};

#endif // MOVIE_H
