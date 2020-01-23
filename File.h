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

    std::string getType() const;
    std::optional<std::string> getMetaData(const std::string) const;
    std::string getContent() const;
    
private:
    std::map<std::string, std::string> metadata; // todo shared_ptr, żeby nie kopiować(?)
    std::string fileType, fileContent;
    static std::regex matchMetadata, matchType, matchContent;
};

#endif // FILE_H
