#ifndef TRACK_H
#define TRACK_H

#include "File.h"
#include "PlaylistEntry.h"

class Track : public PlaylistEntry {
public:
    Track(File file) : file(file) {}
    Track() = default;
    virtual ~Track() = default;
    virtual void play() const = 0;
    virtual std::shared_ptr<Track> newTrack(File) = 0;

protected:
    File file;
};

#endif // TRACK_H
