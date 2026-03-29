#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Developer.h"
#include "Project.h"

using namespace std;

class FileManager {
private:
    const string DEV_FILE = "developers.txt";
    const string PROJ_FILE = "projects.txt";

public:
    void saveDevelopers(vector<Developer*>&);
    void loadDevelopers(vector<Developer*>&);
    void saveProjects(vector<Project*>&);
    void loadProjects(vector<Project*>&);
};

#endif