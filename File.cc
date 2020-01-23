#include <iostream>

#include "File.h"
#include "PlayerException.h"

std::regex File::matchType("^([^|]+)\\|"); // file type should be non-empty string without '|'
std::regex File::matchMetadata("^(?:([^:^|]*):([^|]*)\\|)");
std::regex File::matchContent("^[a-zA-Z0-9\\s,.!?':;-]*$");

File::File(std::string data) {
    try {
        std::string::const_iterator it = data.cbegin();
        std::smatch match;
        
        // match file type
        if (!std::regex_search(data, match, matchType)) {
            throw FileException(std::string("corrupt file"));
        } else {
            fileType = match[1];
            it = match[0].second; 
        }
        
        // match all metadata
        while (std::regex_search(it, data.cend(), match, matchMetadata)) {
            metadata[match[1]] = match[2];
            
            it = match[0].second;
        }
        
        // match file content
        if (!std::regex_search(it, data.cend(), match, matchContent)) {
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

std::string File::getType() const {
    return fileType;
}

std::optional<std::string> File::getMetaData(const std::string fieldName) const {
    auto it = metadata.find(fieldName);
    if (it != metadata.end()) 
        return it->second;
    return {};
}

std::string File::getContent() const {
    return fileContent;
}