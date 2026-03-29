#include "FileManager.h"
#include <fstream>
#include <sstream>

using namespace std;

void FileManager::saveDevelopers(vector<Developer*>& list) {
    ofstream file(DEV_FILE);
    for (auto d : list) {
        file << d->getDevID() << ","
             << d->getName() << ","
             << d->getBirthYear() << ","
             << d->getLanguages() << ","
             << d->getSalary() << endl;
    }
    file.close();
}

void FileManager::loadDevelopers(vector<Developer*>& list) {
    ifstream file(DEV_FILE);
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, by, lang, sal;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, by, ',');
        getline(ss, lang, ',');
        getline(ss, sal, ',');

        Developer* d = new Developer(id, name, stoi(by), lang, stod(sal));
        list.push_back(d);
    }
    file.close();
}

void FileManager::saveProjects(vector<Project*>& list) {
    ofstream file(PROJ_FILE);
    for (auto p : list) {
        file << p->getProjectID() << ","
             << p->getDevID() << ","
             << p->getName() << ","
             << p->getDuration() << ","
             << p->getStartDate() << endl;
    }
    file.close();
}

void FileManager::loadProjects(vector<Project*>& list) {
    ifstream file(PROJ_FILE);
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string pid, did, name, dur, sd;

        getline(ss, pid, ',');
        getline(ss, did, ',');
        getline(ss, name, ',');
        getline(ss, dur, ',');
        getline(ss, sd, ',');

        Project* p = new Project(pid, did, name, stoi(dur), sd);
        list.push_back(p);
    }
    file.close();
}