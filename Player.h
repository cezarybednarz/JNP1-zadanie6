#ifndef PLAYER_H
#define PLAYER_H

#include "Track.h"
#include "File.h"
#include "Playlist.h"

class Player {
public:

	Player() = default;
	~Player() = default;

	Track openFile(File file);
	Playlist createPlaylist(const std::string& name);

private:
};

Track Player::openFile(File file) {

}

Playlist createPlaylist(const std::string& name) {

}

#endif //PLAYER_H
