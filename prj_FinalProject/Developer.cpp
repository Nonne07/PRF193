#include "Developer.h"
#include <sstream>
#include <iomanip>

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

string formatSalary(double salary) {
    string s = to_string((long long)salary);
    string result = "";
    int count = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        result = s[i] + result;
        count++;
        if (count == 3 && i != 0) {
            result = "." + result;
            count = 0;
        }
    }
    return result;
}

void Developer::display() {
    cout << left
         << setw(10) << devID
         << setw(20) << name
         << setw(10) << birthYear
         << setw(20) << languages
         << setw(10) << formatSalary(salary) << endl;
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