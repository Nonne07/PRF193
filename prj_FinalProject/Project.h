#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>

using namespace std;

class Project {
private:
    string projectID;
    string devID;
    string name;
    int duration;
    string startDate;

public:
    Project();
    Project(string pid, string did, string n, int d, string sd);

    string getProjectID() const { return projectID; }
    string getDevID()     const { return devID; }
    string getName()      const { return name; }
    int    getDuration()  const { return duration; }
    string getStartDate() const { return startDate; }

    void setProjectID(string pid) { projectID = pid; }
    void setDevID(string did)     { devID = did; }
    void setName(string n)        { name = n; }
    void setDuration(int d)       { duration = d; }
    void setStartDate(string sd)  { startDate = sd; }

    void input();
    void display();
    string toString();
};

#endif