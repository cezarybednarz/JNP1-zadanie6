#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <memory>

#include "PlayingMode.h"
#include "PlaylistEntry.h"

class Playlist : public PlaylistEntry {

public:

    Playlist();
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

#endif // PLAYLIST_H
