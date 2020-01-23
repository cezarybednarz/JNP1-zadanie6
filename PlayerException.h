#ifndef PLAYEREXCEPTION_H
#define PLAYEREXCEPTION_H

#include <exception>

class PlayerException : public std::exception {
public:
    PlayerException(std::string msg) : msg(msg) {}
    virtual ~PlayerException() = default;
    
    const char * what () const throw () {
        return msg.c_str();
    }
    
private:
    std::string msg;
};

class FileException : public PlayerException {
public:
    FileException(std::string msg) : PlayerException(msg) {}
};

class PlaylistException : public PlayerException {
public:
    PlaylistException(std::string msg) : PlayerException(msg) {}
    virtual ~PlaylistException() = default;
};

class AllocationException : public PlayerException {
public:
    AllocationException(std::string msg) : PlayerException(msg) {}
};

class IndexOutOfRange : public PlaylistException {
public:
    IndexOutOfRange(std::string msg) : PlaylistException(msg) {}
};

#endif //PLAYEREXCEPTION_H
