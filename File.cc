#include <iostream>
#include "File.h"
#include "PlayerException.h"

// std::regex File::matchMetadata("(?:([^|]+)\\|)*");
std::regex File::matchType("^([^|]+)\\|"); // file type should be non-empty string without '|'
std::regex File::matchMetadata("^(?:([^:^|]*):([^|]*)\\|)");
std::regex File::matchContent("^[a-zA-Z0-9\\s,.!?':;-]*$"); // todo check if '-' matches correctly

File::File(std::string data) {
    try {
        std::string::const_iterator it = data.cbegin();
        std::smatch match;
        
        // match file type
        if (!std::regex_search(data, match, matchType)) {
            // std::cout << "not matched" << std::endl;
            throw FileException(std::string("corrupt file"));
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
            // std::cout << "not matched" << std::endl;
            throw FileException(std::string("corrupt content"));
        } else {
            fileContent = match[0];
        }
    } catch (std::bad_alloc &e) {
        throw AllocationException("allocation failed");
    } catch (std::regex_error &e) {
        throw FileException("regular expression failed");
    } catch (FileException &e) {
        throw; 
    } catch (...) {
        throw PlayerException("something went wrong");
    }
}

std::string File::getType() {
    return fileType;
}

std::optional<std::string> File::getMetaData(std::string fieldName) {
    if (metadata.find(fieldName) != metadata.end()) 
        return metadata[fieldName];
    return {};
}

std::string File::getContent() {
    return fileContent;
}