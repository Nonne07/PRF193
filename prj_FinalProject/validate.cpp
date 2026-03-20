#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

#include "date.h"
#include "validate.h"
#include "beautify.h"

using namespace std;

bool isPosFloat(const string& str)
{
    int dotCount = 0;
    int digitCount = 0;
    int i = 0;

    // bỏ khoảng trắng đầu
    while (i < str.size() && str[i] == ' ')
        i++;

    for (; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (!isdigit(str[i]))
        {
            return false;
        }
        else
        {
            digitCount++;
        }
    }

    return digitCount > 0;
}

void inputPosFloat(float& target, const string& prompt)
{
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!isPosFloat(input))
        {
            cout << "Please enter a positive number.\n";
            continue;
        }

        target = stof(input);
        return;
    }
}


//Positive integer number
bool isPosInteger(const string& s) {
    size_t i = 0;

    while (i < s.size() && s[i] == ' ') i++;

    if (i < s.size() && s[i] == '-') return false;

    if (i < s.size() && s[i] == '+') i++;

    bool digitFound = false;

    for (; i < s.size(); i++) {
        if (!isdigit((unsigned char)s[i])) {
            return false;
        }
        digitFound = true;
    }

    return digitFound;
}

void inputPosInteger(int& target, const string& prompt)
{
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!isPosInteger(input))
        {
            cout << "Please enter a valid positive integer.\n";
            continue;
        }

        target = stoi(input);
        return;
    }
}

//Name
bool isValidName(string& name) {
    beautifyName (name);
	
	if (name.empty()) {
        cout << "Empty name\n";
        return false;
    }
    
	int nameLength = 0;
	for (char c : name){
		if (c == ' ') nameLength++;
	}
	if (nameLength < 1) return false;
	
    if (name.length() > 50) {
        cout << "Name too long\n";
        return false;
    }

    for (char c : name) {
        if (!isalpha((unsigned char)c) && c != ' ') {
            cout << "Invalid characters in name\n";
            return false;
        }
    }
    
    cout << "✓Valid name\n";
    return true;
}

//Leap year
bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
// DOB (int the past)
bool isValidDOB(const date& dob) {
    int d = dob.day;
    int m = dob.month;
    int y = dob.year;

    if (d <= 0 || m <= 0 || m > 12 || y <= 0 || y < 1900) {
        cout << "Invalid date\n";
		return false;
    }

    int maxDay;
    if (m == 2) maxDay = isLeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) maxDay = 30;
    else maxDay = 31;

    if (d > maxDay) {
        cout << "Invalid date\n";
		return false;
    }

    time_t t = time(nullptr); // Lấy thời điểm hiện tại
    tm* now = localtime(&t);

    int curD = now->tm_mday;
    int curM = now->tm_mon + 1;
    int curY = now->tm_year + 1900;

    if (y > curY ||
        (y == curY && m > curM) ||
        (y == curY && m == curM && d > curD)) {
        cout << "Future date not allowed\n";
        return false;
    }

    cout << "✓Valid date\n";
    return true;
}

//Appointment date (in the future)
bool isValidAppointmentDate(const date& dob) {
    int d = dob.day;
    int m = dob.month;
    int y = dob.year;

    if (d <= 0 || m <= 0 || m > 12 || y <= 0 || y < 1900) {
        cout << "Invalid date\n";
		return false;
    }

    int maxDay;
    if (m == 2) maxDay = isLeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) maxDay = 30;
    else maxDay = 31;

    if (d > maxDay) {
        cout << "Invalid date\n";
		return false;
    }

    time_t t = time(nullptr); // Lấy thời điểm hiện tại
    tm* now = localtime(&t);

    int curD = now->tm_mday;
    int curM = now->tm_mon + 1;
    int curY = now->tm_year + 1900;

    if (y < curY ||
        (y == curY && m < curM) ||
        (y == curY && m == curM && d < curD)) {
        cout << "Appointment date must in the future";
        return false;
    }

    cout << "✓Valid appointment date\n";
    return true;
}

//Blood type
bool isValidBloodtype (string& bloodType){
	if (!isPosInteger (bloodType)){
		cout << "Invalid blood type choosing";
		return false;
	}
	
	int blood = stoi(bloodType);
	
	if (blood > 8 || blood < 1){
		cout << "Invalid blood type choosing";
		return false;
	}
	
	cout << "✓Valid blood type\n";
	return true;
}

// Contact number
bool isValidContactNumber(const string& contact) {

    if (contact.length() < 7 || contact.length() > 11) {
        cout << "Invalid phone number length\n";
        return false;
    }

    for (char c : contact) {
        if (!isdigit((unsigned char)c)) {
            cout << "Invalid phone number (digits only)\n";
            return false;
        }
    }

    cout << "✓ Valid phone number\n";
    return true;
}

