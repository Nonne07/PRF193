#ifndef VALIDATE_H
#define VALIDATE_H

#include <string>
#include "date.h"

using namespace std;

// Positive integer number (string version)
bool isPosInteger(const string& s);
void inputPosInteger(int& target, const string& prompt);

// Positive float number (string version)
bool isPosFloat(const string& str);
void inputPosFloat(float& target, const string& prompt);


// Name
bool isValidName(string& name);

// Leap year
bool isLeapYear(int year);

// Date of birth (must be in the past)
bool isValidDOB(const date& dob);

// Appointment date (must be in the future)
bool isValidAppointmentDate(const date& date);

// Blood type (1 - 8)
bool isValidBloodtype(string& bloodType);

// Contact number
bool isValidContactNumber(const string& contact);

#endif // VALIDATE_H