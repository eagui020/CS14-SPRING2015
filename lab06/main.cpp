///
//  Eric Aguirre
//  861174273
//  5/12/15
//  Create iterators for the beginning of the vector being looked at(will move
//  when smallest is placed mkaing vector smaller), one for the smallest value,
//  and one to compare the rest of the elements to the smallest to find the
//  lowest value. Then iterate through and swap if the lowest found is lower
//  than the beginning.
///
#include "selectionsort.h"
#include <iostream>
#include <utility>
#include <vector>
#include <list>

using namespace std;

int main() {
    
    //integer test
    vector<int> test1;
    test1.push_back(2);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(1);
    test1.push_back(8);
    test1.push_back(9);
    cout << "pre:\t";
    for (auto i = test1.begin(); i != test1.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    selectionsort(test1);
    cout << "post:\t";
    for (auto i = test1.begin(); i != test1.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl << endl;
    
    //Empty test
    list<int> list1;
    cout << "pre:\t";
    for (auto i = list1.begin(); i != list1.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    selectionsort(list1);
    cout << "post:\t";
    for (auto i = list1.begin(); i != list1.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl << endl;
    
    //(1,2) (3,-1) (-1,3) (0,0) (2,3) (1,2) (1,-2) (8,10)
    vector<pair<int, int> > test2;
    test2.push_back(make_pair(1, 2));
    test2.push_back(make_pair(3, -1));
    test2.push_back(make_pair(-1, 3));
    test2.push_back(make_pair(0, 0));
    test2.push_back(make_pair(2, 3));
    test2.push_back(make_pair(1, 2));
    test2.push_back(make_pair(1, -2));
    test2.push_back(make_pair(8, 10));
    cout << "pre:\t";
    for (auto i = test2.begin(); i != test2.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl;
    selectionsort(test2);
    cout << "post:\t";
    for (auto i = test2.begin(); i != test2.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl << endl;
    
    //(10,2) (-3,-1) (-8,0) (1,1) (1,1) (0,0) (10,2) (5,5) (5,-5) (0,0) (10,2)
    list<pair<int, int> > list2;
    list2.push_back(make_pair(10, 2));
    list2.push_back(make_pair(-3, -1));
    list2.push_back(make_pair(-8, 0));
    list2.push_back(make_pair(1, 1));
    list2.push_back(make_pair(1, 1));
    list2.push_back(make_pair(0, 0));
    list2.push_back(make_pair(10, 2));
    list2.push_back(make_pair(5, 5));
    list2.push_back(make_pair(5, -5));
    list2.push_back(make_pair(0, 0));
    list2.push_back(make_pair(10, 2));
    cout << "pre:\t";
    for (auto i = list2.begin(); i != list2.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl;
    selectionsort(list2);
    cout << "post:\t";
    for (auto i = list2.begin(); i != list2.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl << endl;
    
    // (-1,3) (0,0) (1,-2) (1,2) (1,2) (2,3) (3,-1) (8,10)
    list<pair<int, int> > list3;
    list3.push_back(make_pair(-1, 3));
    list3.push_back(make_pair(0, 0));
    list3.push_back(make_pair(1, -2));
    list3.push_back(make_pair(1, 2));
    list3.push_back(make_pair(1, 2));
    list3.push_back(make_pair(2, 3));
    list3.push_back(make_pair(3, -1));
    list3.push_back(make_pair(8, 10));
    cout << "pre:\t";
    for (auto i = list3.begin(); i != list3.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl;
    selectionsort(list3);
    cout << "post:\t";
    for (auto i = list3.begin(); i != list3.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl << endl;
    
    //single element
    vector<pair<int, int> > single;
    single.push_back(make_pair(-1, 3));
    cout << "pre:\t";
    for (auto i = single.begin(); i != single.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl;
    selectionsort(single);
    cout << "post:\t";
    for (auto i = single.begin(); i != single.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl << endl;
    
    // stable test case
    cout << "Stable test" << endl;
    single.push_back(make_pair(-1, 3));
    single.push_back(make_pair(-2, 3));
    //moves should be 6 as two swaps are needed to make sure the first pair of
    //(-1,3) is in front of the 2nd
    cout << "pre:\t";
    for (auto i = single.begin(); i != single.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl;
    selectionsort(single);
    cout << "post:\t";
    for (auto i = single.begin(); i != single.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl << endl;
    
    
    return 0;
}
