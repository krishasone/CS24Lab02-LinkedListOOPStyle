// intlist.cpp
// Implements class IntList
// Krisha Soneji 4/16/2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    Node* n = head;
    int sum = 0;
    while (n != nullptr) {
        sum += n->info;
        n = n->next;
    }
    return sum;
     // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* n = head;
    while (n != nullptr) {
        if (n->info == value) {
            return true;
        }
        n=n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* n = head;
    if (head == nullptr) {
        return 0;
    }
    int maxval = head->info;
    while (n != nullptr) {
        if (n->info > maxval) {
            maxval = n->info;
        }
        n=n->next;
    }
    return maxval;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head==nullptr){
        return 0.0;
    }
    return sum()/count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node();
    newNode->info = value;
    newNode->next = head;
    head = newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* n = head;
    Node* newNode = new Node();
    newNode->info = value;
    newNode->next = nullptr;
    if (n == nullptr) {
        n = newNode;
        head = newNode;
    }
    else{
        while (n->next!=nullptr){
            n = n->next;
        }
        n->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
    Node* n = head;
    int count = 0;
    while (n != nullptr) {
        count++;
        n = n->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

