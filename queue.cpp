// queue.cpp
// Author: Malla grönqvist

#include "queue.h"

// Declaration of class Node.
class Node {
public:
    Node *next;     // Pointer to next node.
    Item data;      // Stored data.
    Node (Node *n, Item newData) : next(n), data(newData) {}    // Constructor for initializing.
};

//  Function definitions for member functions in QIterator and QList.

QIterator::QIterator() {
    node = 0;
}

QIterator::QIterator(Node *n) {
    node = n;   // Set node to the parameter value.
}

Item &QIterator::operator*() const {
    return node->data; // Return reference to a Person object.
}

QIterator &QIterator::operator++() {
    if(!node )
        return *this;
    node = node->next;  // Increment the node position.
    return *this;   // Return a reference to the iterator.
}

QIterator QIterator::operator++(int) {
    QIterator tmp = *this;
    node = node->next;  // Increment the node position.
    return tmp;     // Return a reference to the iterator before incrementing.
}

bool QIterator::operator!=(const QIterator &qi) const {
    // Compare element on the left with the one on the right. Return true/false.
    return node != qi.node;
}

QList::~QList() {
    while (first != 0) {    // Continue until the end of the list.
        Node *tmp = first;  // Set tmp to first.
        first = first->next;  // Increment first to next node's position.
        delete tmp;     // Free space that tmp points to.
    }
}

void QList::enque(Item item) {
    // Check whether the queue is empty.
    if(isEmpty()) {
        // If the queue is empty, the pointer to next node is set to nullptr (end)
        // The new node is the first and the last node.
        // Initialize node with item data.
        first = last = new Node(nullptr, item);
    }
    else {
        // If the queue is not empty, the current last node is set to
        // point to the new node. New node points to the end.
        last->next = new Node(nullptr, item);
        // The new node is now the last node.
        last = last->next;
    }

}

bool QList::deque(Item &item) {
    // Check whether the queue is empty
    if(isEmpty()) {
        // if the queue is empty no person can be dequeued.
        return false;
    } else {
        // Store first node in tmp and set next node as first.
        Node *tmp = first;
        first = first->next;
        // Set the reference variable to the data contained
        // in the dequeued node.
        item = tmp->data;
        // Free the memory allocated for the dequeued node
        // and return true.
        delete tmp;
        return true;
    }

}

bool QList::del(Item item) {
    Node *current = first;
    Node *prev = nullptr;
    // Iterate over all the nodes in the queue.
    while (current != nullptr) {
        // Check if the data in the current node is the given item.
        if (current->data == item) {
            if (current == first) {
                // If the item is first in the queue, update the value of the first field.
                first = current->next;
            } else if (current == last) {
                // If the given item is the last item, the previous item is set to be the last item.
                last = prev;
                prev->next = nullptr;
            } else {
                // In case the item is between two nodes.
                // Set the previous node to point to the one following the current one.
                prev->next = current->next;
            }
            // Free allocated memory and return true.
            delete current;
            return true;
        }
        // Update the previous node to be the current node and the current node to be the next node.
        prev = current;
        current = current->next;
    }
}

bool QList::isEmpty() const {
    // Check whether first node is end of list. Return true/false.
    return first == 0;
}
