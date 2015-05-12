#include "lab5.h"
#include <map>

using namespace std;

int main() {
    
    BST<int> test1;
    test1.insert(50);
    test1.insert(20);
    test1.insert(60);
    test1.insert(70);
    test1.insert(40);
    test1.insert(10);
    test1.insert(45);
    test1.insert(35);
    // Part 1
    test1.displayMinCover();
    
    // Part 2
    int arr[1000];
    // use printSumPath to print
    test1.printSumPath(test1.root, 80, arr);
    test1.printSumPath(test1.root, 70, arr);
    
    //Part3
    int hd = 0;
    map<int, int> m;
    // Use printVertSum to print
    test1.printVertSum(test1.root, hd, m);
    
    return 0;
}