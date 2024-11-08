
#include <bits/stdc++.h>
using namespace std;

int Fact(int num) 
{
    if (num == 0)
        return 1;

    return num * Fact(num - 1); 
}

int main()  
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int s = Fact(num);
    cout<<"The factorial of "<<num<<" is : "<< s ; 
    return 0;
}