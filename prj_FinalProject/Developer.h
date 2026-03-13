#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <iostream>
#include <string>
using namespace std;

class Developer {
public:
    string devID;
    string name;
    int birthYear;
    string languages;
    double salary;

    Developer();
    Developer(string, string, int, string, double);

    void input();
    void display();
    string toString();
};

#endif