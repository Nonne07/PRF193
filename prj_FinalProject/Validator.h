#pragma once
#include <string>

using namespace std;

class Validator {
private:
    bool isNumber(const string& s);

public:
    bool isValidDevID(const string& id);
    bool isValidProjectID(const string& id);

    bool isValidName(const string& name);
    bool isValidBirthYearFormat(const string& yearStr);
    bool isValidBirthYear(int year);
    bool isValidSalary(double salary);
    bool isValidLanguages(const string& lang);

    bool isValidDuration(int duration);
    bool isValidStartDate(const string& date);
};
