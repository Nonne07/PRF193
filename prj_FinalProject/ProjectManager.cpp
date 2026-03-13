#include "ProjectManager.h"

vector<Project>& ProjectManager::getList() {
    return projectList;
}

bool ProjectManager::projectExists(string id) {
    for (auto &p : projectList)
        if (p.projectID == id)
            return true;

    return false;
}

bool ProjectManager::developerHasProject(string devID) {
    for (auto &p : projectList)
        if (p.devID == devID)
            return true;

    return false;
}

void ProjectManager::assignProject(DeveloperManager &dm) {
    Project p;
    p.input();

    if (!dm.exists(p.devID))
        throw runtime_error("Developer does not exist");

    if (projectExists(p.projectID))
        throw runtime_error("Project ID already exists");

    if (p.duration <= 0)
        throw runtime_error("Invalid duration");

    projectList.push_back(p);

    cout << "Project assigned successfully\n";
}

void ProjectManager::totalExperience() {
    string id;
    cout << "Developer ID: ";
    cin >> id;

    int total = 0;

    for (auto &p : projectList)
        if (p.devID == id)
            total += p.duration;

    cout << "Total Experience: " << total << " months\n";
}

void ProjectManager::groupProject() {
    string id;
    cout << "Developer ID: ";
    cin >> id;

    bool found = false;

    for (auto &p : projectList) {
        if (p.devID == id) {
            p.display();
            found = true;
        }
    }

    if (!found)
        cout << "No projects\n";
}