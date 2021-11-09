// name.h
// Malla Grönqvist


#include "name.h"
#include <iostream>
using namespace std;


Name::Name() {
    firstName = "";
    lastName = "";
}

Name::Name(string pFirstName, string pLastName) {
    firstName = pFirstName;
    lastName = pLastName;
}

void Name::setFirstName(string pFirstName) {
    firstName = pFirstName;
}

void Name::setLastName(string pLastName) {
    lastName = pLastName;
}

string Name::getFirstName() const {
    return firstName;
}

string Name::getLastName() const {
    return lastName;
}

// Separate function for print. Not part of the class Name.
void showName(Name const &name) {
    cout << endl;
    cout << "First name: " << name.getFirstName() << endl;
    cout << "Last Name: " << name.getLastName() << endl;
}

// Overloaded operators.
bool Name::operator<(const Name &name) const {
    if (lastName == name.lastName){
        return firstName < name.firstName;
    } else {
        return lastName < name.lastName;
    }
}

bool Name::operator==(const Name &name) const {
    return firstName == name.firstName && lastName == name.lastName;
}

// Overloaded operators for saving to and reading from file.
const char DELIM = '|'; // Delimiter in between data members in text file.

ostream &operator<<(ostream &os, const Name &name) {
    os << name.getFirstName() << DELIM;
    os << name.getLastName();
    return os;
}

istream &operator>>(istream &is, Name &name) {
    string tmpString;
    getline(is,tmpString,DELIM); // Read until DELIM into tmpString.
    name.setFirstName(tmpString);  // Set first name with the value of tmpString.

    getline(is,tmpString,DELIM);
    name.setLastName(tmpString);

    return is;
}
