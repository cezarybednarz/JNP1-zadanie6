#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <memory>

#include "PlayingMode.h"
#include "PlaylistEntry.h"

class Playlist : public PlaylistEntry {

public:

    Playlist() = default;
    ~Playlist() = default;

    void add(const std::shared_ptr<PlaylistEntry> &playlistEntry);
    void add(const std::shared_ptr<PlaylistEntry> &playlistEntry, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(const std::shared_ptr<PlayingMode> &mode);
    void play() override;

private:
    std::vector<std::shared_ptr<PlaylistEntry>> tracks;
    std::shared_ptr<PlayingMode> playingMode;
};


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


#endif // PLAYLIST_H
