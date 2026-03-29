#include "Validator.h"
#include <cctype>
#include <string>

using namespace std;

bool Validator::isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

bool Validator::isValidDevID(const string& id) {
    if (id.length() < 3) return false;
    if (id[0] != 'D' || id[1] != 'E') return false;
    for (int i = 2; i < (int)id.length(); i++)
        if (!isdigit(id[i])) return false;
    return true;
}

bool Validator::isValidProjectID(const string& id) {
    if (id.length() < 2 || id[0] != 'P') return false;
    for (int i = 1; i < (int)id.length(); i++)
        if (!isdigit(id[i])) return false;
    return true;
}

bool Validator::isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name)
        if (c != ' ') return true;
    return false;
}

bool Validator::isValidBirthYearFormat(const string& yearStr) {
    return yearStr.length() == 4 && isNumber(yearStr);
}

bool Validator::isValidBirthYear(int year) {
    return year >= 1950 && year <= 2025;
}

bool Validator::isValidSalary(double salary) {
    return salary > 0 && salary <= 1000000000;
}

bool Validator::isValidLanguages(const string& lang) {
    if (lang.empty()) return false;
    for (char c : lang)
        if (c != ' ') return true;
    return false;
}

bool Validator::isValidDuration(int duration) {
    return duration > 0 && duration <= 1000;
}

bool Validator::isValidStartDate(const string& date) {
    if (date.length() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(date[i])) return false;
    }

    int day   = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year  = stoi(date.substr(6, 4));

    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 2000 || year > 2100) return false;

    return true;
}