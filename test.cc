#include <iostream>

#include "lib_playlist.h"

void cycle_test1();

int main() {
    // cycle_test1();

    Player player;
    
    auto song = player.openFile(File("audio|title:drivers|artist:car|whales"));
    
    return 0;
}

void cycle_test1() {
    Player player;
    
    auto A = player.createPlaylist("A");
    auto B = player.createPlaylist("B");
    auto C = player.createPlaylist("C");

    A->add(B);
    A->play();

    B->add(C);
    A->play();

    // making C_3 
    try {
        C->add(A); // powinno zwracac wyjatek
        std::cout << __FUNCTION__ << ":" << __LINE__ << " failed" << std::endl;
        return;
    } catch (PlayerException &e) {}
    
    // adding playlist to itself
    try {
        A->add(A); // powinno zwracac wyjatek
        std::cout << __FUNCTION__ << ":" << __LINE__ << " failed" << std::endl;
        return;
    } catch (PlayerException &e) {}
    
    auto A_prim = A;
    
    // adding playlist to itself, but copied
    try {
        A->add(A_prim); // powinno zwracac wyjatek
        std::cout << __FUNCTION__ << ":" << __LINE__ << " failed" << std::endl;
        return;
    } catch (PlayerException &e) {}
    
    try { 
        A_prim->add(A); // powinno zwracac wyjatek
        std::cout << __FUNCTION__ << ":" << __LINE__ << " failed" << std::endl;
        return;
    } catch (PlayerException &e) {}
    
    // adding one playlist to another many times
    try { 
        for (int i = 0; i < 10; i++)
            A->add(B);
    } catch (PlayerException &e) {
        std::cout << __FUNCTION__ << ":" << __LINE__ << " failed" << std::endl;
        return;
    }
    
    std::cout << __FUNCTION__ << " OK" << std::endl;
}
