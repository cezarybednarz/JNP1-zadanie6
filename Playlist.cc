#include "Playlist.h"

// TODO sprawdzać czy playlista tworzy cykl

Playlist::Playlist(const std::string& _name) {
    playingMode = createSequenceMode();
	name = _name;
}

void Playlist::add(const std::shared_ptr<PlaylistEntry> &playlistEntry) {
    try {
        tracks.push_back(playlistEntry);
    } catch(std::bad_alloc &e) {
        throw AllocationException("allocation failed");
    }
}

void Playlist::add(const std::shared_ptr<PlaylistEntry> &playlistEntry, size_t position) {
    if(position <= tracks.size()) {
        tracks.emplace(tracks.begin()+position, playlistEntry);
    } else {
        throw IndexOutOfRange("index out of range");
    }
}

void Playlist::remove() {
    if(!tracks.empty()) {
        tracks.pop_back();
    } else {
        throw PlaylistException("remove() on empty playlist");
    }

}

void Playlist::remove(size_t position) {
    if(position < tracks.size()) {
        tracks.erase(tracks.begin()+position);
    } else {
        throw IndexOutOfRange("index out of range");
    }
}

void Playlist::setMode(const std::shared_ptr<PlayingMode> &mode) {
    playingMode = mode;
}

void Playlist::play() {
    try {
        std::vector<size_t> order = playingMode->getOrder(tracks.size());
        for (size_t id : order) {
            tracks[id]->play();
        }
    } catch(std::exception &e) {
        throw e;
    } catch(...) {
        throw PlaylistException("something went wrong");
    }
}

