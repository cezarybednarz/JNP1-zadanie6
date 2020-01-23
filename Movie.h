#ifndef MOVIE_H
#define MOVIE_H

#include "File.h"
#include "Track.h"
#include <string>
#include <regex>

// TODO try static registration??

class Movie : public Track {
public:
    Movie() = default;
    Movie(File);
    ~Movie() = default;
    void play() override;
    std::shared_ptr<Track> newTrack(File) override;
    
private:
    static std::string decode(std::string);
    static std::regex matchYear;
};

#endif // MOVIE_H
