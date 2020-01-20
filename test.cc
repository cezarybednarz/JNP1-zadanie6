#include <iostream>

#include "File.h"
#include "Track.h"
#include "Song.h"
#include "TrackFactory.h"

int main() {
    
    File f("audio|asd:dsa");
    
    TrackFactory b;
    
    b.registerTrack("audio", std::make_shared<Song>());
    
    auto a = b.createTrack(f);
    
    // for (auto a : f.metadata) {
    //     std::cout << a.first << ": " << a.second << std::endl;
    // }
    
    return 0;
}