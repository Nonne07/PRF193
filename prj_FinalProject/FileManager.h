#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Developer.h"
#include "Project.h"

class FileManager {
public:

    static void saveDevelopers(vector<Developer>&);
    static void loadDevelopers(vector<Developer>&);

    static void saveProjects(vector<Project>&);
    static void loadProjects(vector<Project>&);

};

#endif