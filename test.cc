#include <iostream>

#include "lib_playlist.h"

int main() {

    // testuje sprawdzanie zagniezdzenia przy playlist->add

    Player player;

    auto A = player.createPlaylist("A");
    auto B = player.createPlaylist("B");
    auto C = player.createPlaylist("C");

    A->add(B);
    A->play();

    B->add(C);
    A->play();

    C->add(A); // powinno zwracac wyjatek

    //A->play();


    //mishmash->play();
    
    // for (auto a : f.metadata) {
    //     std::cout << a.first << ": " << a.second << std::endl;
    // }
    
    return 0;
}