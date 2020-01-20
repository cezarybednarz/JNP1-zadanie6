#include "TrackFactory.h"


std::shared_ptr<Track> TrackFactory::createTrack(File file) {
    return registeredTracks[file.getType()]->newTrack(file);
}

void TrackFactory::registerTrack(std::string name, std::shared_ptr<Track> track) {
    registeredTracks[name] = track;
}
