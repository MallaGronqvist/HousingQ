// name.h
// Author: Malla Grönqvist

#ifndef DT019G_NAME_H
#define DT019G_NAME_H

#include <string>

using namespace std;

class Name {

private:
    string firstName; 
    string lastName;

public:
    Name ();   
    Name (string pFirstName, string pLastName);    

    void setFirstName (string pFirstName);      
    void setLastName (string pLastName);

    string getFirstName () const;       
    string getLastName () const;        // Const-declared because values are not changed.

    // Overloaded operators.
    bool operator<(const Name &name) const;
    bool operator==(const Name &name) const;

};

// Overloaded operators for saving to and reading from file.
ostream &operator<<(ostream &os, const Name &name);
istream &operator>>(istream &is, Name &name);


// Separate function for print.
void showName(Name const &name);

#endif //DT019G_NAME_H
