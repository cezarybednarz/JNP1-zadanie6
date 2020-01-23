#include <iostream>

#include "lib_playlist.h"

void cycle_test1();
void parsing_test1();
void parsing_test2();
// void negative_parsing(std::string);

int main() {
    Player player;
    // auto a6 = player.openFile(File("video|"));
    cycle_test1();

    parsing_test1();
    parsing_test2();
    // Player player;
    
    // auto song = player.openFile(File("audio|title:drivers|artist:car|whales"));
    
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

void negative_parsing(std::string data) {
    Player player;
    
    try {
        auto a = player.openFile(File(data));
        std::cout << "ERR: " << data << "parsed correctly, but shouldn't" << std::endl;
    } catch (PlayerException &e) {
    
    }
}

void parsing_test1() {
    Player player;
    
    // positive
    
    auto a1 = player.openFile(File("video|title:asd|year:1234|xyz"));
    auto a2 = player.openFile(File("audio|title:asd|year:1234|artist:asd|xyz"));
    auto a3 = player.openFile(File("video|title:asd|year:1234|other metadata:some data with whitespaces|xyz"));
    auto a4 = player.openFile(File("video|title:asd|year:1234|:empty metadata name|xyz"));
    auto a4_5 = player.openFile(File("video|title:asd|year:1234|:|<-both:empty|content"));
    auto a5 = player.openFile(File("video|title:asd|year:1234|empty metadata:|xyz"));
    auto a6 = player.openFile(File("video|multiple:colons:in:metadata|title:asd|year:1234|xyz"));
    auto a7 = player.openFile(File("video|title:multiple:colons:in:title|year:1234|xyz"));
    auto a8 = player.openFile(File("video|title:multiple:colons:in:title|year:1234|")); // empty content
    auto a8_5 = player.openFile(File("video|title:multiple:colons:in:title|year:1234|tylko 1 znak alfanumeryczny,\n biae znaki oraz nastujce znaki specjalne: ,.!?':;-"));
    std::cout << "title should be multiple:colons:in:title" << std::endl;
    a7->play();
    
    // same metadata multiple times
    std::string file = "video|title:film|";
    
    for (int i = 0; i < 1000; i++) {
        file += "year:" + std::to_string(i) + "|";
    }
    
    file += "content";
    
    auto a9 = player.openFile(File(file));
    std::cout << "year should be 999" << std::endl;
    a9->play();
    
    std::cout << __FUNCTION__ << " OK" << std::endl;
}

void parsing_test2() {
    negative_parsing("");
    negative_parsing("alsudhflaksdhfla");
    // brak metadanych
    negative_parsing("audio|lyrics");
    negative_parsing("audio|title:jest|lyrics");
    negative_parsing("audio|artist:jest|lyrics");
    negative_parsing("video|title:jest|film");
    negative_parsing("video|year:12|film");
    negative_parsing("video|film");
    
    // year should be a number
    negative_parsing("video|title:asdf|year:asdf|film");
    negative_parsing("video|title:asdf|year:12sdf|film");
    negative_parsing("video|title:asdf|year:ser12sdf|film");
    negative_parsing("video|title:asdf|year:ser12|film");
    
    negative_parsing("video|title:asdf|year:12|correct content@#@not really");
    
    // incorrent metadata
    negative_parsing("video|title:asdf||corrent content");
    
    
    std::cout << __FUNCTION__ << " OK" << std::endl;
}