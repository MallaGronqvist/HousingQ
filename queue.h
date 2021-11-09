// queue.h
// Author: Malla Grönqvist

#ifndef DT019G_QUEUE_H
#define DT019G_QUEUE_H

#include "person.h"

typedef Person Item;
class Node;
class QIterator {
private:
    Node *node;
public:
    QIterator();   
    QIterator(Node *n);     
    // Overloaded operators
    Item &operator*() const;
    QIterator &operator++();    // Prefix ++i
    QIterator operator++(int);      // Postfix i++
    bool operator!=(const QIterator &qi) const;
};

//---------------------------------------------------------------------------

class QList {
private:
    Node *first, *last;
public:
    QList():first(nullptr),last(nullptr){};
    ~QList();

    void enque(Item item);
    bool deque(Item &item);
    bool del(Item item);
    bool isEmpty()const;

    QIterator begin()const {return QIterator(first);}
    QIterator end() const {return QIterator(nullptr);}
};

#endif //DT019G_QUEUE_H
