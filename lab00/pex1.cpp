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

int main(){
    
    int Num;
    int result;
    cout << "Enter user number" << endl;
    cin >> Num;
    
    result = GetSumofDigits(Num);
    
    cout << result << endl;
    return 0;
}