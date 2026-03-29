#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>
#include <string>
#include "Project.h"

using namespace std;

class DeveloperManager;

class ProjectManager {
private:
    vector<Project*> projectList;

public:
    ~ProjectManager();

    vector<Project*>& getList();
    bool projectExists(string id);
    bool developerHasProject(string devID);

    void assignProject(DeveloperManager &dm);
    void totalExperience();
    void groupProject();
};

#endif