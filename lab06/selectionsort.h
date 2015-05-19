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
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <utility>
#include <iostream>

using namespace std;

template<typename L>
void selectionsort(L &l)
{
    auto begin = l.begin();
    if (begin == l.end()) return; //empty case
    int moves = 0; //move counter
    //smallest is pos after beginning by default
    auto smallest = l.begin();
    ++smallest;
    if (smallest == l.end()) return;
    //position to compare to smallest to find lowest value
    auto toCompare = smallest;
    ++toCompare;
    
    while(begin != l.end())
    {
        while(toCompare != l.end())
        {
            if(*smallest > *toCompare) //find smallest
            {
                smallest = toCompare;
            }
            ++toCompare;
        }
        if(*smallest < *begin) //swap smallest
        {
            swap(*smallest, *begin);
            moves += 3; //swap is 3 moves
        }
        //Move begin 1 pos and the move the rest accordingly as with the start
        ++begin;
        smallest = begin;
        ++smallest;
        if (smallest == l.end()) break; //if begin is last or only element
        toCompare = smallest;
        ++toCompare;
    }
    
    cout << "0 copies and " << moves << " moves" << endl;
    return;
}

#endif