// adress.h
// Author: Malla Grönqvist

#ifndef DT019G_ADDRESS_H
#define DT019G_ADDRESS_H

#include <string>
using namespace std;

class Address {

private:
    string streetAddress; 
    string postNum;
    string city;

public:
    Address (); 
    // Constructor for initialization of data members.
    Address (string pStreetAddress, string pPostNum, string pCity);

    void setStreetAddress (string pStreetAddress);
    void setPostNum (string pPostNum);
    void setCity (string pCity);

    string getStreetAddress () const;
    string getPostNum () const;
    string getCity () const;

    // Overloaded operators.
    bool operator<(const Address &address) const;
    bool operator==(const Address &address) const;

};

// Overloaded operators for saving to and reading from file.
ostream &operator<<(ostream &os, const Address &address);
istream &operator>>(istream &is, Address &address);

// Separate function for print.
void showAddress (Address const &address);


#endif //DT019G_ADDRESS_H
