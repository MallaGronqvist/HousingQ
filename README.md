# HousingQ

This is a console application written in C++ that simulates a housing queue.

## Purpose

My goal with this project has been to practice using linked lists and iterators and to understand how
a queue can be built as an abstract data type. 
Creating this project has taught me how nodes and pointers/iterators can be used when working on a dynamically linked list.
I also learned how to build a queue as a class.


### Technical description

The classes Person, Address and Name are used to handle data on a detailed level. 
Moreover, the classes Node and QIterator are used to save and access data in the queue. Nodes and iterators
are needed because the queue is not a static data container but a dynamically linked list. Hence, it is not possible
to access data in the queue by for example using an index (which would be possible in the case of an array) and
it is necessary to use iterators. Further, the class QList provides member functions built on the classes Node and
QIterator that are used for processing data in the queue. Finally the class housingQ forms the user interface 
and with its member functions the housingQ class makes it possible for the user to interact with the housing queue.
The main program creates an object of the class housingQ and uses its member function run() to access the other
member functions that work on the data in the housing queue.


