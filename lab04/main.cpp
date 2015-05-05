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

#include "lab4.h"
#include <utility>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    // check for arguments
    if ( argc != 2 )
    {
        cout << "Usage: coprimeTree <int_max>" << endl;
        exit(-1);
    }
    //convert argument into int
    istringstream ss(argv[1]);
    int k;
    if (!(ss >> k))
    {
        cout << "Invalid number " << argv[1] << '\n';
        exit(-1);
    }
    coprimePrint(k);
    return 0;
}