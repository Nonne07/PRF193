#include "Project.h"
#include <sstream>
#include "iomanip"
Project::Project() {}

Project::Project(string pid, string did, string n, int d, string sd) {
    projectID = pid;
    devID = did;
    name = n;
    duration = d;
    startDate = sd;
}

void Project::input() {
    cout << "Project ID: ";
    cin >> projectID;

    cout << "Developer ID: ";
    cin >> devID;
    cin.ignore();

    cout << "Project Name: ";
    getline(cin, name);

    cout << "Duration (months): ";
    cin >> duration;

    cout << "Start Date: ";
    cin >> startDate;
}

void Project::display() {
    cout << left
         << setw(10) << projectID
         << setw(10) << devID
         << setw(20) << name 
         << setw(10) << duration 
         << setw(10) << startDate << endl;
}

string Project::toString() {
    stringstream ss;
    ss << projectID << ","
       << devID << ","
       << name << ","
       << duration << ","
       << startDate;
    return ss.str();
}
