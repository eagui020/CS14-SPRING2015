///
//  Eric Aguirre
//  861174273
//  4/7/15
//  Make Node class, then Lab1List class definition, define each function one by
//  one and test in main.
///
#include "Lab1List.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor

Lab1List::Lab1List() : head(0), tail(0) {}


Lab1List::Lab1List(const string& str)
{
    head = 0;
    tail = 0;
    //Construct a singly-linked list from the passed string(does not mean string
    //typed object). Each character should go into separate node.
    for (unsigned int i = 0; i < str.size(); ++i)
    {
        push(str.at(i)); // add each character one by one
    }
}

//destructor

Lab1List::~Lab1List()
{
    // Delete front Node until empty
    while(head != 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == 0)
        {
            tail = 0;
        }
    }
    if (head == 0)
    {
        return;
    }
}


void Lab1List::push(char val)
{
    // Inserts a data value (within a new node) at the back end of the list.
    //create temp for tail to hold it
    if (head == 0)
    {
        push_front(val); //add to front if empty
        return;
    }
    // Save old tail and point its next to new tail and point tail to new tail
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
    return;
}


void Lab1List::display() const
{
    // Go through each node and display data starting with head
    if(head == 0)
    {
        return;
    }
    cout << head->data;
    Node *temp = head->next;
    while(temp != 0)
    {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
    return;
}


void Lab1List::push_front(char value)
{
    // This function inserts a data value (within a new node) at the front end of the list.
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
    if (tail == 0)
    {
        tail = head;
    }
    return;
}


void Lab1List::rotate(int k)
{
    Node *before;
    Node *temp;
    for (int i = 0; i < k; ++i)
    {
        before = head; // Keep track of Node before current
        while(before->next != tail) //stop when before is at the end
        {
            before = before->next;
        }
        //Make the 2nd to last Node point to 0 making it the new end
        before->next = 0;
        temp = head; //save head to have new head point to it
        tail->next = temp; //Make old tail new head
        head = tail;
        tail = before;
    }
    return;
}


Lab1List& Lab1List::operator+(Lab1List& head1)
{
    //check if any of the lists are empty
    if (head != 0 && head1.head != 0)
    {
        //add head datas and make a pointer to the next node
        head->data = (head->data + head1.head->data);
        Node *curr1 = head->next;
        Node *curr2 = head1.head->next;
        while (curr1 != 0 || curr2 != 0) //check if need to copy node, add, or leave alone
        {
            if (curr1 != 0 && curr2 != 0) //add
            {
                curr1->data = (curr1->data + curr2->data);
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            else if(curr1 == 0 && curr2 != 0) //push element
            {
                push(curr2->data);
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            else //done
            {
                return *this;
            }
        }
        return *this;
    }
    else if(head != 0 && head1.head == 0)
    {
        return *this;
    }
    else if(head == 0 && head1.head != 0) //copy
    {
        push(head1.head->data);
        Node *curr2 = head1.head->next;
        while (curr2 != 0)
        {
            push(curr2->data);
            curr2 = curr2->next;
        }
        return *this;
    }
    else
    {
        return *this;
    }
}
