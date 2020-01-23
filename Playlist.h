#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <memory>

#include "PlayingMode.h"
#include "PlaylistEntry.h"
#include "PlayerException.h"

class Playlist : public PlaylistEntry {

public:
    explicit Playlist() = default;
    explicit Playlist(const std::string& _name);
    ~Playlist() = default;


    void add(const std::shared_ptr<PlaylistEntry> &playlistEntry);
    void add(const std::shared_ptr<PlaylistEntry> &playlistEntry, size_t position);
    void remove();
    void remove(size_t position);
    void setMode(const std::shared_ptr<PlayingMode> &mode);
    void play() const override;
    bool exists(PlaylistEntry *elem) override;
private:

	std::string name;
    std::vector<std::shared_ptr<PlaylistEntry>> tracks;
    std::shared_ptr<PlayingMode> playingMode;
};

#endif // PLAYLIST_H
