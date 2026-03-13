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

//Getters
    string getDevID()     const;
    string getName()      const;
    int    getBirthYear() const;
    string getLanguages() const;
    double getSalary()    const;

//Setters
    void setDevID    (string devID);
    void setName     (string name);
    void setBirthYear(int birthYear);
    void setLanguages(string languages);
    void setSalary   (double salary);

    void input();
    void display();
    string toString();
};


#endif
