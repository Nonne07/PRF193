#pragma once
#include <string>

class Validator {
public:
    static bool isValidDevID(const std::string& id);
    static bool isValidProjectID(const std::string& id);

    static bool isNumber(const std::string& s);

    static bool isValidName(const std::string& name);
    static bool isValidBirthYearFormat(const std::string& yearStr);
    static bool isValidBirthYear(int year);
    static bool isValidSalary(double salary);
    static bool isValidLanguages(const std::string& lang);

    static bool isValidDuration(int duration);
    static bool isValidStartDate(const std::string& date);
};