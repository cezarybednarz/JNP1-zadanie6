#include "Playlist.h"


// TODO dodac wyjatki
// TODO sprawdzać czy playlista tworzy cykl

Playlist::Playlist(const std::string& _name) {
    playingMode = createSequenceMode();
	name = _name;
}

void Playlist::add(const std::shared_ptr<PlaylistEntry> &playlistEntry) {
    tracks.push_back(playlistEntry);
}

void Playlist::add(const std::shared_ptr<PlaylistEntry> &playlistEntry, size_t position) {
    tracks.emplace(tracks.begin() + position, playlistEntry);
}

void Playlist::remove() {
    tracks.pop_back();
}

void Playlist::remove(size_t position) {
    tracks.erase(tracks.begin() + position);
}

void Playlist::setMode(const std::shared_ptr<PlayingMode> &mode) {
    playingMode = mode;
}

void Playlist::play() {
    std::vector<size_t> order = playingMode->getOrder(tracks.size());
    for(size_t id : order) {
        tracks[id]->play();
    }
}

