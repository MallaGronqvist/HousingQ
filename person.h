// person.h
// Author: Malla Grönqvist

#ifndef DT019G_PERSON_H
#define DT019G_PERSON_H

#include "name.h"
#include "address.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person {

    private:       
    Name name;
    Address address;
    string personNr;
    int shoeSize;

    public:     
    Person ();  
    Person (Name pName, Address pAddress, string pPersonNr, int pShoeSize);

    void setName (Name pName);
    void setAddress (Address pAddress);
    void setPersonNr (string pPersonNr);
    void setShoeSize (int pShoeSize);

    Name getName () const { return name;}
    Address getAddress () const { return address;}
    string getPersonNr () const { return personNr;}
    int getShoeSize () const { return shoeSize;}

    // Overloaded operators.
    bool operator<(const Person &person) const;
    bool operator==(const Person &person) const;

};

// Overloaded operators for saving to and reading from file.
ostream &operator<<(ostream &os, const Person &person);
istream &operator>>(istream &is, Person &person);

// Separate functions for entering and viewing persons, and printing name and address.

void printName (Name const &n);

void printAddress (Address const &a);

void enterPerson (vector<Person> &persons);

void viewPersons (vector<Person> persons);

#endif //DT019G_PERSON_H
