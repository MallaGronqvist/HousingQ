// adress.cpp
// Author: Malla Grönqvist

#include "address.h"
#include <iostream>

using namespace std;

Address::Address () {
   streetAddress = "";
   postNum = "";
   city = "";
}

Address::Address (string pStreetAddress, string pPostNum, string pCity) {
    streetAddress = pStreetAddress;
    postNum = pPostNum;
    city = pCity;
}

void Address::setStreetAddress (string pStreetAddress) {
    streetAddress = pStreetAddress;
}
void Address::setPostNum (string pPostNum) {
    postNum = pPostNum;
}
void Address::setCity (string pCity) {
    city = pCity;
}

string Address::getStreetAddress () const {
    return streetAddress;
}
string Address::getPostNum () const {
    return postNum;
}

string Address::getCity () const {
    return city;
}

// Separate function for print. Not part of the class Address.
void showAddress (Address const &address) {
    cout << endl;
    cout << "Street Address: " << address.getStreetAddress() << endl;
    cout << "Post number: " << address.getPostNum() << endl;
    cout << "City: " << address.getCity() << endl;
}

// Overloaded operators.
bool Address::operator<(const Address &address) const {
    if (city == address.city){
        return streetAddress < address.streetAddress;
    } else {
        return city < address.city;
    }
}

bool Address::operator==(const Address &address) const {
    return streetAddress == address.streetAddress && city == address.city
    && postNum == address.postNum;
}

// Overloaded operators for saving to and reading from file.
const char DELIM = '|'; // Delimiter in between data members in text file.

ostream &operator<<(ostream &os, const Address &address) {
    os << address.getStreetAddress() << DELIM;
    os << address.getPostNum() << DELIM;
    os << address.getCity();

    return os;
}

istream &operator>>(istream &is, Address &address) {
    string tmpString;
    getline(is,tmpString,DELIM); // Read until DELIM into tmpString.
    address.setStreetAddress(tmpString); // Set value of street address.

    getline(is,tmpString,DELIM);
    address.setPostNum(tmpString);

    getline(is,tmpString,DELIM);
    address.setCity(tmpString);

    return is;
}

