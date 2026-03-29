#include "DeveloperManager.h"
#include "ProjectManager.h"
#include "Validator.h"
#include <algorithm>

DeveloperManager::~DeveloperManager() {
    for (auto d : devList)
        delete d;
    devList.clear();
}

vector<Developer*>& DeveloperManager::getList() {
    return devList;
}

bool DeveloperManager::exists(string id) {
    for (auto d : devList)
        if (d->getDevID() == id)
            return true;
    return false;
}

void DeveloperManager::addDev() {
    Developer* d = new Developer();

    string id;
    cout << "Developer ID: ";
    cin >> id;
    if (!Validator::isValidDevID(id)) {
        delete d;
        throw runtime_error("Invalid Developer ID");
    }
    if (exists(id)) {
        delete d;
        throw runtime_error("Developer ID already exists");
    }
    d->setDevID(id);

    cin.ignore();
    string name;
    cout << "Name: ";
    getline(cin, name);
    if (!Validator::isValidName(name)) {
        delete d;
        throw runtime_error("Invalid Name");
    }
    d->setName(name);

    string byStr;
    cout << "Birth Year: ";
    cin >> byStr;
    if (!Validator::isValidBirthYearFormat(byStr)) {
        delete d;
        throw runtime_error("Invalid Birth Year format");
    }
    int by = stoi(byStr);
    if (!Validator::isValidBirthYear(by)) {
        delete d;
        throw runtime_error("Birth Year out of range (1950-2025)");
    }
    d->setBirthYear(by);

    cin.ignore();
    string lang;
    cout << "Languages: ";
    getline(cin, lang);
    if (!Validator::isValidLanguages(lang)) {
        delete d;
        throw runtime_error("Invalid Languages");
    }
    d->setLanguages(lang);

    double sal;
    cout << "Salary: ";
    cin >> sal;
    if (!Validator::isValidSalary(sal)) {
        delete d;
        throw runtime_error("Invalid Salary");
    }
    d->setSalary(sal);

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
        if ((*it)->getDevID() == id) {
            delete *it;
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

    for (auto d : devList) {
        if (d->getDevID() == id) {
            d->display();
            return;
        }
    }

    cout << "Developer not found\n";
}

void DeveloperManager::updateSalary() {
    string id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto d : devList) {
        if (d->getDevID() == id) {
            double newSalary;
            cout << "New Salary: ";
            cin >> newSalary;
            if (!Validator::isValidSalary(newSalary)) {
                throw runtime_error("Invalid Salary");
            }
            d->setSalary(newSalary);
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
        [](Developer* a, Developer* b){ return a->getSalary() < b->getSalary(); });

    if (choice == 2)
        sort(devList.begin(), devList.end(),
        [](Developer* a, Developer* b){ return a->getName() < b->getName(); });

    if (choice == 3)
        sort(devList.begin(), devList.end(),
        [](Developer* a, Developer* b){ return a->getBirthYear() < b->getBirthYear(); });

    displayAll();
}

void DeveloperManager::displayAll() {
    for (auto d : devList)
        d->display();
}