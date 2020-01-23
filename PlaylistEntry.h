#ifndef PLAYLISTENTRY_H
#define PLAYLISTENTRY_H

class PlaylistEntry {
public:
    virtual void play() = 0;
	virtual bool exists(PlaylistEntry* elem);
    virtual ~PlaylistEntry() = default;
};

#endif // PLAYLISTENTRY_H
