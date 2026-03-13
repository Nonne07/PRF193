#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>
using namespace std;

class Project {
public:
    string projectID;
    string devID;
    string name;
    int duration;
    string startDate;

    Project();
    Project(string, string, string, int, string);

    void input();
    void display();
    string toString();
};

#endif