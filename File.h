#ifndef FILE_H
#define FILE_H

#include <string.h>
#include <regex>
#include <map>
#include <optional>
    
class File {
public:
    File(std::string);
    File() = default;

    std::string getType();
    std::optional<std::string> getMetaData(std::string);
    std::string getContent();
    
private:
    std::map<std::string, std::string> metadata;
    std::string fileType, fileContent;
    static std::regex matchMetadata, matchType, matchContent;
};

#endif // FILE_H
