#ifndef MOVIE_H
#define MOVIE_H

#include "File.h"
#include "Track.h"
#include <string>

// TODO try static registration??

class Movie : public Track {
public:
    Movie() = default;
    Movie(File);
    void play() override;
    std::shared_ptr<Track> newTrack(File) override;
    
private:
    static std::string decode(std::string);
};

#endif // MOVIE_H
