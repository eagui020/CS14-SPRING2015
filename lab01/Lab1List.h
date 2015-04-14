///
//  Eric Aguirre
//  861174273
//  4/7/15
//  Make Node class, then Lab1List class definition, define each function one by
//  one and test in main.
///
#ifndef LAB1LIST_H
#define LAB1LIST_H

#include "Node.h"
#include <string>

using namespace std;

class Lab1List
{
    private:
        Node *head;
        Node *tail;
    public:
        Lab1List();
        Lab1List(const string& str);
        ~Lab1List(); //using pop-front to delete one by one
        void push(char val);
        void display() const;
        void rotate(int k);
        Lab1List& operator+(Lab1List& head1);
        void push_front(char value); //add to front if head = 0
};

#endif