#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <vector>
#include "Project.h"
#include "DeveloperManager.h"

class ProjectManager {
private:
    vector<Project> projectList;

public:
    vector<Project>& getList();

    bool projectExists(string id);
    bool developerHasProject(string devID);

    void assignProject(DeveloperManager &dm);
    void totalExperience();
    void groupProject();
};

#endif