#ifndef TRACK_FACTORY_H
#define TRACK_FACTORY_H

// map

#include "Track.h"
#include "File.h"

class TrackFactory {
public:
    std::shared_ptr<Track> createTrack(File);
    
    void registerTrack(std::string, std::shared_ptr<Track>);
private:
    std::map<std::string, std::shared_ptr<Track>> registeredTracks;
};

#endif // TRACK_FACTORY_H