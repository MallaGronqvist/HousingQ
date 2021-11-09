// person.cpp
// Author: Malla Grönqvist

#include "person.h"
#include <iostream>


Person::Person() {
    personNr = "";
    shoeSize = 0;
}

Person::Person(Name pName, Address pAddress, string pPersonNr, int pShoeSize) {
    name = pName;
    address = pAddress;
    personNr = pPersonNr;
    shoeSize = pShoeSize;
}

void Person::setName(Name pName) {
    name = pName;
}

void Person::setAddress(Address pAddress) {
    address = pAddress;
}

void Person::setPersonNr(string pPersonNr) {
    personNr = pPersonNr;
}

void Person::setShoeSize(int pShoeSize) {
    shoeSize = pShoeSize;
}

// Functions for printing name and address. Not part of the class.
void printName(Name const &n) {
     cout << n.getFirstName() << ", " << n.getLastName();
}

void printAddress(Address const &a) {
    cout << a.getStreetAddress() << ", " << a.getPostNum() << ", " << a.getCity();
}

// Function for entering data. Not part of the class.
void enterPerson(vector<Person> &persons) {
    Person temporaryPerson; // A Person object that will temporarily hold the entered data.
    string firstName, lastName, personNr, streetAddress, zipCode, city;
    int shoeSize;

    cout << "ADD A PERSON" << endl
         << "***************************************************************" << endl;
    cout << "Enter first name: " << endl;
    getline (cin, firstName);   // Read in user input.
    cout << "Enter last name: " << endl;
    getline(cin, lastName);
    cout << "Enter social number: " << endl;
    getline(cin,personNr);
    cout << "Enter street address: " << endl;
    getline(cin,streetAddress);
    cout << "Enter zip code: " << endl;
    getline(cin,zipCode);
    cout << "Enter city: " << endl;
    getline(cin,city);
    cout << "Enter shoe size: " << endl;
    cin >> shoeSize;
    cin.get();

    // Set values of temporaryPerson.
    temporaryPerson.setName(Name(firstName, lastName));
    temporaryPerson.setPersonNr(personNr);
    temporaryPerson.setAddress(Address(streetAddress, zipCode, city));
    temporaryPerson.setShoeSize(shoeSize);

    persons.push_back(temporaryPerson); // Save the data to the vector.
}

// Function for viewing data in the vector. Not part of the class.
void viewPersons(vector<Person> persons) {
    // Print from vector item by item.
    for (int i = 0; i < persons.size(); i++) {
        cout << "PERSON DATA" << endl
        << "***************************************************************" << endl;
        cout << "Name: "; printName(persons[i].getName());
        cout << endl
        << "Address: "; printAddress(persons[i].getAddress());
        cout << endl;
        cout << "Social number: " << persons[i].getPersonNr() << endl;
        cout << "Shoe size: " << persons[i].getShoeSize() << endl
        << "***************************************************************" << endl;
    }

}

// Overloaded operators.
bool Person::operator<(const Person &person) const {
    if (name == person.name){
        return address < person.address;
    } else {
        return name < person.name;
    }
}

bool Person::operator==(const Person &person) const {
    return name == person.name && address == person.address
    && personNr == person.personNr && shoeSize == person.shoeSize;
}

// Overloaded operators for saving to and reading from file.
const char DELIM = '|'; // Delimiter in between data members in text file.

ostream &operator<<(ostream &os, const Person &person) {
    Name tmpName (person.getName());
    os << tmpName.getFirstName() << DELIM;
    os << tmpName.getLastName() << DELIM;
    Address tmpAddress (person.getAddress());
    os << tmpAddress.getStreetAddress() << DELIM;
    os << tmpAddress.getPostNum() << DELIM;
    os << tmpAddress.getCity() << DELIM;
    os << person.getPersonNr() << DELIM;
    os << person.getShoeSize();

    return os;
}

istream &operator>>(istream &is, Person &person) {
    string tmpString1, tmpString2, tmpString3;
    getline(is,tmpString1, DELIM); // Read until DELIM into tmpString.
    getline(is,tmpString2, DELIM);
    person.setName(Name(tmpString1, tmpString2));

    getline(is,tmpString1, DELIM);
    getline(is,tmpString2, DELIM);
    getline(is,tmpString3, DELIM);
    person.setAddress(Address(tmpString1, tmpString2, tmpString3));

    getline(is,tmpString1, DELIM);
    person.setPersonNr(tmpString1);

    int tmpInt;
    is >> tmpInt;
    is.get();
    person.setShoeSize(tmpInt);

    return is;
}

