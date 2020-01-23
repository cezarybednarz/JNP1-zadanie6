#include "TrackFactory.h"
#include "PlayerException.h"

std::shared_ptr<Track> TrackFactory::createTrack(const File file) const {
    auto it = registeredTracks.find(file.getType());
    if (it != registeredTracks.end()) {
        return it->second->newTrack(file);
    } else {
        throw FileException("unsupported type");
    }
}

void TrackFactory::registerTrack(std::string name, std::shared_ptr<Track> track) {
    try {
        registeredTracks[name] = track;
    } catch (std::bad_alloc &e) {
        throw AllocationException("allocation failed");
    }
}
