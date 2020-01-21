#ifndef TRACK_H
#define TRACK_H

#include "File.h"

// TODO try static registration??

class Track {
public:
    Track(File file) : file(file) {}
    Track() = default;
    virtual void play() = 0;
    virtual std::shared_ptr<Track> newTrack(File) = 0;

protected:
    File file;
};

#endif // TRACK_H
