#ifndef TRACK_FACTORY_H
#define TRACK_FACTORY_H

#include "Track.h"
#include "File.h"

class TrackFactory {
public:
    std::shared_ptr<Track> createTrack(const File) const;
    
    void registerTrack(std::string, std::shared_ptr<Track>);
private:
    std::map<std::string, std::shared_ptr<Track>> registeredTracks;
};

#endif // TRACK_FACTORY_H