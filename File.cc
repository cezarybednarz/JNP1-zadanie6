#include <iostream>
#include "File.h"

// std::regex File::matchMetadata("(?:([^|]+)\\|)*");
std::regex File::matchType("^([a-zA-Z]+)\\|"); // file type should be non-empty alphabetic string
std::regex File::matchMetadata("^(?:([^:^|]*):([^|]*)\\|)");
std::regex File::matchContent("^[^|]");

File::File(std::string data) {
    std::string::const_iterator it = data.cbegin();
    std::smatch match;
    
    // match file type
    if (!std::regex_search(data, match, matchType)) {
        std::cout << "not matched" << std::endl;
        // throw
    } else {
        fileType = match[1];
        it = match[0].second; // TODO co jak wyjdzie poza stringa
    }

    // match all metadata
    while (std::regex_search(it, data.cend(), match, matchMetadata)) {
        // std::cout << "matched metadata: " << match[1] << "->" << match[2] << std::endl;
        metadata[match[1]] = match[2];
        
        it = match[0].second;
    }
    
    // match file content
    if (!std::regex_search(it, data.cend(), match, matchContent)) {
        std::cout << "not matched" << std::endl;
        // throw
    } else {
        fileContent = match[0];
    }

}

std::string getType() {
    return fileType;
}