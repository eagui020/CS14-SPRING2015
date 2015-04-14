///
//  Eric Aguirre
//  861174273
//  4/7/15
//  Make Node class, then Lab1List class definition, define each function one by
//  one and test in main.
///
#include <iostream>
#include <string>
#include "Lab1List.h"
#include "Node.h"

using namespace std;

int main() {
    string str = "abcde";
    Lab1List case1("123456");
    case1.display();
    Lab1List case2(str);
    case2.display();
    case1.rotate(4);
    case1.display();
    case2.rotate(4);
    case2.display();
    
    Lab1List case3(str);
    Lab1List case4;
    Lab1List case7("hello");
    case7.display();
    Lab1List case5("bye");
    case5.display();
    Lab1List case6;
    case6 = case7 + case5;
    case6.display();
    Lab1List case8;
    Lab1List case9;
    case9 = case1 + case8;
    case8 = case2 + case3;
    case9.display();
    case8.display();
    return 0;
}