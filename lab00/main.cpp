#include <iostream>

using namespace std;

int GetSumofDigits(int userinp)
{
    int sum = 0;
    while (userinp != 0)
    {
        sum += userinp % 10;
        userinp /= 10;
    }
    return sum;
}

void swapInts(int &userNum1, int &userNum2)
{
    userNum2 = (userNum1 - userNum2);
    userNum1 -= userNum2;
    userNum2 += userNum1;
    
}
int main(){
    int ex = 0;
    cout << "Enter Ex #";
    cin >> ex;
    cout << endl;
    if (ex == 2)
    {
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
    }
    if (ex == 1)
    {
        int Num;
        int result;
        cout << "Enter user number" << endl;
        cin >> Num;
        
        result = GetSumofDigits(Num);
        
        cout << result << endl;
    }
    return 0;
}