///
//  Eric Aguirre
//  861174273
//  4/7/15
//  Make Node class, then Lab1List class definition, define each function one by
//  one and test in main.
///
#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        char data;
        Node *next;
        Node( char data ) : data(data), next(0) {}
};

#endif