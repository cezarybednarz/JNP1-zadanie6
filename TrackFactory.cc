#include "TrackFactory.h"


std::shared_ptr<Track> TrackFactory::createTrack(File file) {
    return registeredTracks[file.getType()]->newTrack(file);
}

void TrackFactory::registerTrack(std::string name, std::shared_ptr<Track> track) {
    try {
        registeredTracks[name] = track;
    } catch (std::bad_alloc &e) {
        throw new AllocationException();
    }
}
