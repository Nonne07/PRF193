#include "Developer.h"
#include <sstream>

Developer::Developer() {}

Developer::Developer(string id, string n, int by, string lang, double sal) {
    devID = id;
    name = n;
    birthYear = by;
    languages = lang;
    salary = sal;
}

void Developer::input() {
    cout << "Developer ID: ";
    cin >> devID;
    cin.ignore();

    cout << "Name: ";
    getline(cin, name);

    cout << "Birth Year: ";
    cin >> birthYear;
    cin.ignore();

    cout << "Languages: ";
    getline(cin, languages);

    cout << "Salary: ";
    cin >> salary;
}

void Developer::display() {
    cout << devID << " | "
         << name << " | "
         << birthYear << " | "
         << languages << " | "
         << salary << endl;
}

string Developer::toString() {
    stringstream ss;
    ss << devID << ","
       << name << ","
       << birthYear << ","
       << languages << ","
       << salary;
    return ss.str();
}