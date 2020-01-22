#include "TrackFactory.h"
#include "PlayerException.h"

std::shared_ptr<Track> TrackFactory::createTrack(File file) {
    if (registeredTracks.find(file.getType()) != registeredTracks.end()) {
        return registeredTracks[file.getType()]->newTrack(file);
    } else {
        throw FileException("unsupported type");
    }
}

void TrackFactory::registerTrack(std::string name, std::shared_ptr<Track> track) {
    try {
        registeredTracks[name] = track;
    } catch (std::bad_alloc &e) {
        throw new AllocationException("allocation failed");
    }
}
