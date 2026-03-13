#ifndef DEVELOPERMANAGER_H
#define DEVELOPERMANAGER_H

#include <vector>
#include "Developer.h"

class ProjectManager;

class DeveloperManager {
private:
    vector<Developer> devList;

public:
    vector<Developer>& getList();

    bool exists(string id);

    void addDev();
    void removeDev(ProjectManager &pm);
    void searchDev();
    void updateSalary();
    void sortDev();
    void displayAll();
};

#endif