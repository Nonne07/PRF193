#include "FileManager.h"
#include <fstream>
#include <sstream>

using namespace std;

void FileManager::saveDevelopers(vector<Developer>& list) {

    ofstream file("developers.txt");

    for (auto &d : list) {
        file << d.devID << ","
             << d.name << ","
             << d.birthYear << ","
             << d.languages << ","
             << d.salary << endl;
    }

    file.close();
}

void FileManager::loadDevelopers(vector<Developer>& list) {

    ifstream file("developers.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        string id, name, by, lang, sal;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, by, ',');
        getline(ss, lang, ',');
        getline(ss, sal, ',');

        Developer d(
            id,
            name,
            stoi(by),
            lang,
            stod(sal)
        );

        list.push_back(d);
    }

    file.close();
}

void FileManager::saveProjects(vector<Project>& list) {

    ofstream file("projects.txt");

    for (auto &p : list) {
        file << p.projectID << ","
             << p.devID << ","
             << p.name << ","
             << p.duration << ","
             << p.startDate << endl;
    }

    file.close();
}

void FileManager::loadProjects(vector<Project>& list) {

    ifstream file("projects.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        string pid, did, name, dur, sd;

        getline(ss, pid, ',');
        getline(ss, did, ',');
        getline(ss, name, ',');
        getline(ss, dur, ',');
        getline(ss, sd, ',');

        Project p(
            pid,
            did,
            name,
            stoi(dur),
            sd
        );

        list.push_back(p);
    }

    file.close();
}