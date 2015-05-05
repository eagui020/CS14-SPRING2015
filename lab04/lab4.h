///
//  Eric Aguirre
//  861174273
//  5/4/15
//  Start by creating a function that will print all orders in the correct
//  format specified. After, begin making recursive function that will traverse
//  "nodes" for the coprime tree and print the values in the order. However,
//  for the last sorted order, create a priority_queue and push the values onto
//  it instead of outputing while traversing. After, print the contents of the
//  priority queue.
///

#ifndef LAB4_H
#define LAB4_H

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Given priority_queue def
typedef pair<int,int> Entry;
class priority_queue {
    public:
        vector<Entry> entries;
        Entry& front() { return entries.back(); }
        void pop() { entries.pop_back(); }
        void push( Entry e )
        {
            entries.push_back( e );
            for ( int i = entries.size()-1; i != 0; --i )
            {
                // replace this comparison with code for comparing int pairs.
                if ((entries[i].first + entries[i].second) 
                < entries[i-1].first + entries[i-1].second) break;
                swap(entries[i], entries[i-1]);
            }
        }
};

// Preorder output
void coprimePreorderRecursion(int m, int n, int k)
{
    if (m + n < k)
    {
        // cout first
        cout << m << " " << n << endl;
        // (2m - n, m), (2m + n, m) and (m + 2n, n) in that order
        coprimePreorderRecursion(2*m - n, m, k);
        coprimePreorderRecursion(2*m + n, m, k);
        coprimePreorderRecursion(m + 2*n, n, k);
    }
}

// Postorder output
void coprimePostorderRecursion(int m, int n, int k)
{
    if (m + n < k)
    {
        // cout last
        // (2m - n, m), (2m + n, m) and (m + 2n, n) in that order
        coprimePostorderRecursion(2*m - n, m, k);
        coprimePostorderRecursion(2*m + n, m, k);
        coprimePostorderRecursion(m + 2*n, n, k);
        cout << m << " " << n << endl;
    }
}

//Sorted output using priority queue
void coprimeInorderRecursion(int m, int n, int k, priority_queue &sorted)
{
    pair <int, int> temp (m, n); // Make pairs to insert
    if (m + n < k)
    {
        sorted.push(temp); // Sorts data based on sum
        coprimeInorderRecursion(2*m - n, m, k, sorted);
        coprimeInorderRecursion(2*m + n, m, k, sorted);
        coprimeInorderRecursion(m + 2*n, n, k, sorted);
    }
}

void coprimePrint(int k)
{
    //cout both sides in preorder
    cout << "pre-order" << endl;
    coprimePreorderRecursion(2, 1, k);
    coprimePreorderRecursion(3, 1, k);
    
    cout << "post-order" << endl;
    coprimePostorderRecursion(2, 1, k);
    coprimePostorderRecursion(3, 1, k);
    
    cout << "sorted" << endl;
    priority_queue sorted;
    coprimeInorderRecursion(2, 1, k, sorted);
    coprimeInorderRecursion(3, 1, k, sorted);
    // Outputs what is in the the p'queue
    for (int i = sorted.entries.size()-1; i >= 0; --i )
    {
        cout << sorted.entries[i].first << " ";
        cout << sorted.entries[i].second << endl;
    }
}

#endif