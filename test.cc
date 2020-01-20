#include <iostream>

#include "File.h"

int main() {
    
    File f("audio|name:asd");
    
    for (auto a : f.metadata) {
        std::cout << a.first << ": " << a.second << std::endl;
    }
    
    return 0;
}