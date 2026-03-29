#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <iostream>
#include <string>
using namespace std;

class Developer {
private:
    string devID;
    string name;
    int birthYear;
    string languages;
    double salary;

public:
    Developer();
    Developer(string, string, int, string, double);

    string getDevID()     const { return devID; }
    string getName()      const { return name; }
    int    getBirthYear() const { return birthYear; }
    string getLanguages() const { return languages; }
    double getSalary()    const { return salary; }

    void setDevID(string id)       { devID = id; }
    void setName(string n)         { name = n; }
    void setBirthYear(int by)      { birthYear = by; }
    void setLanguages(string lang) { languages = lang; }
    void setSalary(double sal)     { salary = sal; }

    void input();
    void display();
    string toString();
};

#endif