#include <iostream>

using namespace std;

void swapInts(int &userNum1, int &userNum2)
{
    userNum2 = (userNum1 - userNum2);
    userNum1 -= userNum2;
    userNum2 += userNum1;
    return;
}

int main() {
    
    int userNum1;
    int userNum2;
    
    cout << "Enter first number" << endl;
    cin >> userNum1;
    cout << endl;
    
    cout << "Enter second number" << endl;
    cin >> userNum2;
    cout << endl;

    swapInts(userNum1, userNum2);
    
    cout << userNum1 << endl << userNum2 << endl;
    return 0;
}