#ifndef PLAYEREXCEPTION_H
#define PLAYEREXCEPTION_H
#include <exception>

class PlayerException : public std::exception {
	const char * what () const throw () {
		return "PlayerException";
	}
};

class FileException : public PlayerException {
	const char * what () const throw () {
		return "FileException";
	}
};

class PlaylistException : public PlayerException {
	const char * what () const throw () {
		return "PlaylistException";
	}
};

class AllocationException : public PlayerException {
	const char * what () const throw () {
		return "AllocationException";
	}
};

class IndexOutOfRange : public PlaylistException {
	const char * what () const throw () {
		return "IndexOutOfRange";
	}
};

#endif //PLAYEREXCEPTION_H
