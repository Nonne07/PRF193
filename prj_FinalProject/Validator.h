class Validator {
private:
    bool isNumber(const std::string& s); // only used internally by other validators

public:
    bool isValidDevID(const std::string& id);
    bool isValidProjectID(const std::string& id);

    bool isValidName(const std::string& name);
    bool isValidBirthYearFormat(const std::string& yearStr);
    bool isValidBirthYear(int year);
    bool isValidSalary(double salary);
    bool isValidLanguages(const std::string& lang);

    bool isValidDuration(int duration);
    bool isValidStartDate(const std::string& date);
};
