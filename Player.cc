#include "lib_playlist.h"

Player::Player() {
    factory.registerTrack("audio", std::make_shared<Song>());
    factory.registerTrack("video", std::make_shared<Movie>());
}

std::shared_ptr<Track> Player::openFile(File file) {
    return factory.newTrack(file);
}

std::shared_ptr<Playlist> Player::createPlaylist(const std::string& name) {
	return std::make_shared<Playlist> (Playlist(name));
}

