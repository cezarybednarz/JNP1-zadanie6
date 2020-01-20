#include <iostream>
#include "File.h"

std::regex File::matchMetadata("([^|]*)|*");

File::File(std::string data) {
    
    std::smatch m;
    std::regex_match(data, m, matchMetadata);
    
    for (std::smatch::iterator it = m.begin(); it!=m.end(); ++it) {
	       std::cout << *it << std::endl;
    }
    // for (auto m : match) {
    //     std::cout << m << std::endl;
    // }
    
    metadata["name"] = data;
}