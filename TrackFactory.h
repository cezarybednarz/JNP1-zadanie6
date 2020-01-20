#ifndef TRACK_FACTORY_H
#define TRACK_FACTORY_H


#include "Track.h"
#include "File.h"

class TrackFactory {
public:
    Track &createTrack(File);
    
    void registerTrack(Track&);
private:
};

#endif // TRACK_FACTORY_H