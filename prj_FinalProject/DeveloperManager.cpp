#include "DeveloperManager.h"
#include "ProjectManager.h"
#include <algorithm>

vector<Developer>& DeveloperManager::getList() {
    return devList;
}

bool DeveloperManager::exists(string id) {
    for (auto &d : devList)
        if (d.devID == id)
            return true;
    return false;
}

void DeveloperManager::addDev() {
    Developer d;
    d.input();

    if (exists(d.devID))
        throw runtime_error("Developer ID already exists");

    devList.push_back(d);

    cout << "Add developer success\n";
}

void DeveloperManager::removeDev(ProjectManager &pm) {
    string id;
    cout << "Enter ID: ";
    cin >> id;

    if (pm.developerHasProject(id)) {
        cout << "Cannot remove developer with active projects\n";
        return;
    }

    for (auto it = devList.begin(); it != devList.end(); it++) {
        if (it->devID == id) {
            devList.erase(it);
            cout << "Developer removed\n";
            return;
        }
    }

    cout << "Developer not found\n";
}

void DeveloperManager::searchDev() {
    string id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto &d : devList) {
        if (d.devID == id) {
            d.display();
            return;
        }
    }

    cout << "Developer not found\n";
}

void DeveloperManager::updateSalary() {
    string id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto &d : devList) {
        if (d.devID == id) {
            cout << "New Salary: ";
            cin >> d.salary;
            cout << "Update success\n";
            return;
        }
    }

    cout << "Developer not found\n";
}

void DeveloperManager::sortDev() {
    int choice;

    cout << "1. Salary\n";
    cout << "2. Name\n";
    cout << "3. BirthYear\n";
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1)
        sort(devList.begin(), devList.end(),
        [](Developer a, Developer b){ return a.salary < b.salary; });

    if (choice == 2)
        sort(devList.begin(), devList.end(),
        [](Developer a, Developer b){ return a.name < b.name; });

    if (choice == 3)
        sort(devList.begin(), devList.end(),
        [](Developer a, Developer b){ return a.birthYear < b.birthYear; });

    displayAll();
}

void DeveloperManager::displayAll() {
    for (auto &d : devList)
        d.display();
}