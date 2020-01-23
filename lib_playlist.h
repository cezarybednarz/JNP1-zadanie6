#ifndef LIB_PLAYLIST_H
#define LIB_PLAYLIST_H

#include "Song.h"
#include "Movie.h"
#include "Playlist.h"
#include "File.h"
#include "TrackFactory.h"
#include "Track.h"
#include "PlayerException.h"

class Player {
public:
    Player();
    ~Player() = default;

    std::shared_ptr<Track> openFile(File file);
    static std::shared_ptr<Playlist> createPlaylist(const std::string& name);

private:
    static TrackFactory factory;
};

#endif // LIB_PLAYLIST_H