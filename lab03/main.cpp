///
//  Eric Aguirre
//  861174273
//  4/28/15
//  Make each function and test it one at a time.
//  Fixed and FLex are interchangable with only difference being the stop point.
//  For towers think of problems you can do easily then recursively call until
//  you can do the problem
///
#include "lab3.h"
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Ex 1
    TwoStackFixed<int> test1(5, 3);
    test1.pushStack1(5);
    test1.pushStack2(4);
    test1.pushStack2(3);
    // test1.pushStack2(4);
    test1.pushStack1(4);
    test1.pushStack1(7);
    
    cout << test1.popStack1() << endl;
    test1.display();
    cout << test1.popStack1() << endl;
    test1.display();
    
    //char
    TwoStackFixed<char> test2(5, 3);
    test2.pushStack1('a');
    test2.pushStack2('d');
    test2.pushStack2('e');
    test2.pushStack1('h');
    test2.pushStack1('f');
    
    cout << test2.popStack1() << endl;
    test2.display();
    cout << test2.popStack1() << endl;
    test2.display();
    cout << test2.popStack1() << endl;
    test2.display();
    // cout << test2.popStack1() << endl; //empty test
    // test2.display();
    cout << endl;
    
    //Ex2
    cout << "Ex2" << endl;
    TwoStackOptimal<int> test3(5);
    test3.pushFlexStack1(5);
    test3.pushFlexStack1(4);
    test3.pushFlexStack2(3);
    test3.pushFlexStack2(4);
    test3.pushFlexStack1(7);
    // test3.pushFlexStack1(7);
    
    cout << test3.popFlexStack1() << endl;
    test3.display();
    cout << test3.popFlexStack1() << endl;
    test3.display();
    cout << test3.popFlexStack1() << endl;
    test3.display();
    // cout << test3.popFlexStack1() << endl; //empty test
    // test3.display();
    cout << endl;
    
    //Ex3
    cout << "Ex3" << endl;
    stack<int> start;
    stack<int> aux;
    stack<int> dest;
    int i;
    for (i = 4; i > 0; --i) // Change i value for different cases
    {
        start.push(i);
    }
    // cout << i << endl;
    showTowerStates(4, start, aux, dest); //change n to i original
    // TowerDisplay(start, aux, dest); //final outcome
    
    return 0;    
}