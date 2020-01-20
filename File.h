#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <regex>
#include <map>
    
class File {
public:
    File(std::string);

private:
    std::map<std::string, std::string> metadata;
    std::string fileType, fileContent;
    static std::regex matchMetadata, matchType, matchContent;
};

#endif // FILE_H
