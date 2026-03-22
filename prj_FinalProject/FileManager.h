#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Developer.h"

class FileManager {
public:
    static void saveToCSV(const std::vector<Developer>& list, const std::string& filename);
    static void loadFromCSV(std::vector<Developer>& list, const std::string& filename);
};

#endif
