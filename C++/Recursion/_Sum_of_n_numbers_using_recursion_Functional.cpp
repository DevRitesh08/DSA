
#include <bits/stdc++.h>
using namespace std;

int Nsum(int num) {
    if (num == 0)
        return 0;

    return num + Nsum(num - 1);  
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int s = Nsum(num);
    cout<<"The sum of first "<<num<<" natural numbers is : "<< s ; 
    return 0;
}