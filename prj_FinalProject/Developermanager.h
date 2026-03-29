#ifndef DEVELOPERMANAGER_H
#define DEVELOPERMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include "Developer.h"

using namespace std;

class ProjectManager;

class DeveloperManager {
private:
    vector<Developer*> devList;

public:
    ~DeveloperManager();

    vector<Developer*>& getList();
    bool exists(string id);

    void addDev();
    void removeDev(ProjectManager &pm);
    void searchDev();
    void updateSalary();
    void sortDev();
    void displayAll();
};

#endif	