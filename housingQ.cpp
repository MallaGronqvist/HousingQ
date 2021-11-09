// housingQ.cpp
// Author: Malla grönqvist

#include "housingQ.h"
#include <fstream>

housingQ::housingQ() {
    nrOfPersonsInQueue = 0;
}

void housingQ::run() {
    cout << "Enter a filename to load/save the housing queue to: " << endl;
    getline(cin, fileName);  
    fstream inFile;
    inFile.open(fileName, ios::in); // Open file for reading.
    if(inFile.is_open()) {  // If opening the file succeeds.
        Person tmpPerson;
        while (inFile >> tmpPerson){     // Read into tmpPerson using the overloaded
            Qlist.enque(tmpPerson);  // >> operator. Add data to Qlist.
        nrOfPersonsInQueue++;   // Increment the number of persons in queue.
        }
    }
    inFile.close();     // Close file.

    int choice = 0;
    bool repeat = true;
    do {
        choice = menu();    // Print the menu and call member functions
        switch (choice) {   // according to the user's choice.
            case 1: addPersonToQueue();
                break;
            case 2: offerHousing();
                break;
            case 3: displayHousingQ();
                break;
            case 4: displayPerson();
                break;
            case 5: removePerson();
                break;
            case 6: saveToFile();
                break;
            case 7: repeat = false;
        }
    } while ( repeat);
}

int housingQ::menu() {
    int number;
    cout << endl << "***********MENU***********" << endl;   // Print menu.
    cout << "1. Add a person to housing queue." << endl
         << "2. Offer housing to a person." << endl
         << "3. Display housing queue." << endl
         << "4. Display person information." << endl
         << "5. Remove person from housing queue." << endl
         << "6. Save housing queue." << endl
         << "7. Exit program" << endl
         << "***************************" << endl
         << "Input a number from the menu options:" << endl;
    cin >> number;      // Read in user input.
    cin.get();
    return number;  // Return user input.
}

void housingQ::addPersonToQueue() {
    Person temporaryPerson; // A Person object that will temporarily hold the entered data.
    string firstName, lastName, personNr, streetAddress, zipCode, city;
    int shoeSize;
    cout << "*********Add a person to the list********" << endl;
    cout << "Enter first name: " << endl;
    getline (cin, firstName);   // Read in user input.
    cout << "Enter last name: " << endl;
    getline(cin, lastName);
    cout << "Enter social security number: " << endl;
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

    Qlist.enque(temporaryPerson);   // Add person to the queue.
    nrOfPersonsInQueue++;       // Increment the number of persons in queue.
    cout << endl << "The person was added to the queue." << endl
         << "Press ENTER to continue." << endl;
    cin.get();

}

void housingQ::offerHousing() {
    Person temporaryPerson;
    // If a person can be dequeued (list is not empty)
    // Take a person's data away from the queue and place into temporaryPerson.
    if (Qlist.deque(temporaryPerson)) {
        cout << endl << "The first person in queue was offered housing:" << endl
        << "Name: "<< temporaryPerson.getName() << endl
        << "Address: " << temporaryPerson.getAddress() << endl
        << "Social security number: " << temporaryPerson.getPersonNr() << endl
        << "Shoe size: " << temporaryPerson.getShoeSize() << endl;
        nrOfPersonsInQueue--;   // Decrement the number of persons in queue.
    } else {
        cout << "The queue is empty!" << endl;
    }
    cout << endl << "Press ENTER to continue." << endl;
    cin.get();
}

void housingQ::displayHousingQ() {
    if (Qlist.isEmpty()){
        cout << "The queue is empty!" << endl;
    } else {
        cout << "Displaying housing queue." << endl
             << "The queue contains " << nrOfPersonsInQueue << " persons." << endl
             << "*********************************************************" << endl;

        int positionInQue = 1;  // Variable to keep count of queue placement.
        // Iterate over the queue.
        QIterator p;
        for (p = Qlist.begin(); p != Qlist.end(); p++) {
            cout << "Person holding queue number: " << positionInQue << endl;
            cout << "--------------------------------------------------------" << endl;
            // Print person info.
            cout << "Name: ";
            printName((*p).getName());
            cout << endl;
            cout << "Address: ";
            printAddress((*p).getAddress());
            cout << endl;
            cout << "Social security nr: " << (*p).getPersonNr() << endl;
            cout << "Shoe size: " << (*p).getShoeSize() << endl;
            cout << "********************************************************" << endl;
            positionInQue++;
        }
    }
    cout << "Press ENTER to continue." << endl;
    cin.get();
}

void housingQ::displayPerson() {
    cout << "Display person information" << endl
    << "********************************************************" << endl;
    if (!(Qlist.isEmpty())){    // If the queue is not empty.
        string searchTerm;
        cout << "Look up person information by entering the person's social security number: " << endl;
        getline(cin, searchTerm);  // Read user input into searchTerm.
        int positionInQue = 0;
        QIterator p;
        for (p = Qlist.begin(); p != Qlist.end(); p++){     // Iterate over Qlist.
            positionInQue++;    // Keep count of position in queue.
            if ((*p).getPersonNr()==searchTerm){    // If a match is found.
                cout << "Person found:" << endl     // print person info.
                << "Queue number:" << positionInQue << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "Name: ";
                printName((*p).getName());
                cout << endl;
                cout << "Address: ";
                printAddress((*p).getAddress());
                cout << endl;
                cout << "Social security nr: " << (*p).getPersonNr() << endl;
                cout << "Shoe size: " << (*p).getShoeSize() << endl;
                cout << "********************************************************" << endl;
            }
        }
    } else {    // If the queue is empty.
        cout << "The queue is empty!" << endl;
    }
    cout << "Press ENTER to continue." << endl;
    cin.get();
}

void housingQ::removePerson() {
cout << "Remove a person from the housing queue." << endl
<< "**********************************************************" << endl;
    if (!(Qlist.isEmpty())) {    // If the queue is not empty.
        cout << "Enter the person's social security number:" << endl;
        string searchTerm;
        getline(cin, searchTerm);
        Person searchedPerson;
        QIterator p;
        for (p = Qlist.begin(); p!= Qlist.end(); p++) {     // Iterate over Qlist.
            if ((*p).getPersonNr()==searchTerm){
                searchedPerson = *p;
            }
        }
        // If the person can be deleted.
        if(Qlist.del(searchedPerson)) {
            // Print info and decrement number of persons in queue.
            cout << "The person was removed from the housing queue." << endl;
            nrOfPersonsInQueue--;
        // If the person could not be deleted (not found in queue).
        } else {
            // Print info.
            cout << "The person was not found in the housing queue." << endl;
        }

    } else {  // If the queue is empty, print info about this.
    cout << "The housing queue is empty!" << endl;
    }
    cout << "Press ENTER to continue." << endl;
    cin.get();
}

void housingQ::saveToFile() {
    cout << "Housing queue is saved to file: " << fileName << endl;
    fstream outFile(fileName, ios::out); // Open file for writing.
    QIterator p;
    // Iterate over queue and write to file item by item.
    for (p = Qlist.begin(); p != Qlist.end(); p++){
        outFile << (*p) << endl;
    }
    outFile.close();    // Close file.
}


