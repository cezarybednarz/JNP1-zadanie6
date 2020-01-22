#include "lib_playlist.h"

#include "Song.h"
#include "Movie.h"

TrackFactory Player::factory;

Player::Player() {
    factory.registerTrack("audio", std::make_shared<Song>());
    factory.registerTrack("video", std::make_shared<Movie>());
}

std::shared_ptr<Track> Player::openFile(File file) {
    return factory.createTrack(file);
}

std::shared_ptr<Playlist> Player::createPlaylist(const std::string& name) {
	return std::make_shared<Playlist> (Playlist(name));
}

