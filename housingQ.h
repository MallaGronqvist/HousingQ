// housingQ.h
// Author: Malla Grönqvist

#ifndef DT019G_HOUSINGQ_H
#define DT019G_HOUSINGQ_H

#include "queue.h"

class housingQ {
public:
    housingQ();     // Default constructor
    void run();     // Member function for running the program.
private:
    QList Qlist;    // Qlist object
    int nrOfPersonsInQueue;
    string fileName;
    // Member functions
    int menu();
    void addPersonToQueue();
    void offerHousing();
    void displayHousingQ();
    void displayPerson();
    void removePerson();
    void saveToFile();

};

#endif //DT019G_HOUSINGQ_H
