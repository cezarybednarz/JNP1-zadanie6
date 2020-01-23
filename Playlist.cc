#include "Playlist.h"

Playlist::Playlist(const std::string& _name) {
    playingMode = createSequenceMode();
	name = _name;
}

// recursive DFS used to check existence of playlist in children of that playlist
bool Playlist::existsInPlaylist(const std::shared_ptr<PlaylistEntry> &currentPlaylist,
                                const std::shared_ptr<PlaylistEntry> &checkPlaylist) {

    if(currentPlaylist == checkPlaylist) { // todo tutaj jest blad
        printf("co jest\n");
        return true;
    }

    std::cout << "wszedlem >>> " << dynamic_cast<Playlist*>(currentPlaylist.get())->name << " " <<
    dynamic_cast<Playlist*>(checkPlaylist.get())->name << "\n";

    if(typeid(currentPlaylist.get()) == typeid(checkPlaylist.get())) {
        for(auto &item : dynamic_cast<Playlist*>(currentPlaylist.get())->tracks) {
            if(existsInPlaylist(item, checkPlaylist)) {
                return true;
            }
        }
    }
    return false;
}

void Playlist::add(const std::shared_ptr<PlaylistEntry> &playlistEntry) {
    bool nested;
    try {
        nested = existsInPlaylist(playlistEntry, std::make_shared<Playlist>(*this));
    } catch (std::exception &e) {
        throw PlaylistException("failed trying to check self-adding");
    }
    if(nested) {
        throw PlaylistException("playlist nested in itself");
    }

    std::cout << " >>> " << nested << "\n";

    try {
        tracks.push_back(playlistEntry);
    } catch(std::bad_alloc &e) {
        throw AllocationException("allocation failed");
    }
}

void Playlist::add(const std::shared_ptr<PlaylistEntry> &playlistEntry, size_t position) {
    bool nested;
    try {
        nested = existsInPlaylist(playlistEntry, std::make_shared<Playlist>(*this));
    } catch (std::exception &e) {
        throw PlaylistException("failed trying to check self-adding");
    }
    if(nested) {
        throw PlaylistException("playlist nested in itself");
    }

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
    std::cout << "Playlist [" << name << "]\n";
    try {
        std::vector<size_t> order = playingMode->getOrder(tracks.size());
        for (size_t id : order) {
            tracks[id]->play();
        }
    } catch(std::exception &e) {
        throw PlaylistException("error in playlist");
    }
}

