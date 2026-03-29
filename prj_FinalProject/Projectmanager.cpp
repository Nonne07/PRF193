#include "ProjectManager.h"
#include "DeveloperManager.h"
#include "Validator.h"

ProjectManager::~ProjectManager() {
    for (auto p : projectList)
        delete p;
    projectList.clear();
}

vector<Project*>& ProjectManager::getList() {
    return projectList;
}

bool ProjectManager::projectExists(string id) {
    for (auto p : projectList)
        if (p->getProjectID() == id)
            return true;
    return false;
}

bool ProjectManager::developerHasProject(string devID) {
    for (auto p : projectList)
        if (p->getDevID() == devID)
            return true;
    return false;
}

void ProjectManager::assignProject(DeveloperManager &dm) {
    Project* p = new Project();

    string pid;
    cout << "Project ID: ";
    cin >> pid;
    if (!Validator::isValidProjectID(pid)) {
        delete p;
        throw runtime_error("Invalid Project ID");
    }
    if (projectExists(pid)) {
        delete p;
        throw runtime_error("Project ID already exists");
    }
    p->setProjectID(pid);

    string did;
    cout << "Developer ID: ";
    cin >> did;
    if (!dm.exists(did)) {
        delete p;
        throw runtime_error("Developer does not exist");
    }
    p->setDevID(did);

    cin.ignore();
    string name;
    cout << "Project Name: ";
    getline(cin, name);
    if (!Validator::isValidName(name)) {
        delete p;
        throw runtime_error("Invalid Project Name");
    }
    p->setName(name);

    int dur;
    cout << "Duration (months): ";
    cin >> dur;
    if (!Validator::isValidDuration(dur)) {
        delete p;
        throw runtime_error("Invalid Duration");
    }
    p->setDuration(dur);

    string sd;
    cout << "Start Date (DD/MM/YYYY): ";
    cin >> sd;
    if (!Validator::isValidStartDate(sd)) {
        delete p;
        throw runtime_error("Invalid Start Date");
    }
    p->setStartDate(sd);

    projectList.push_back(p);
    cout << "Project assigned successfully\n";
}

void ProjectManager::totalExperience() {
    string id;
    cout << "Developer ID: ";
    cin >> id;

    int total = 0;
    for (auto p : projectList)
        if (p->getDevID() == id)
            total += p->getDuration();

    cout << "Total Experience: " << total << " months\n";
}

void ProjectManager::groupProject() {
    string id;
    cout << "Developer ID: ";
    cin >> id;

    bool found = false;
    for (auto p : projectList) {
        if (p->getDevID() == id) {
            p->display();
            found = true;
        }
    }

    if (!found)
        cout << "No projects found\n";
}