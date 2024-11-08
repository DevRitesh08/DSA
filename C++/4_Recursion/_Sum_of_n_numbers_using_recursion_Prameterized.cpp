
#include <bits/stdc++.h>
using namespace std;

void Nsum(int num, int sum) 
{
    int dup = num ;
    if (num < 1)
    {
        cout<<"The sum of first "<<dup<<" natural numbers is : "<<sum ; 
        return;
    }

    Nsum(num - 1 , sum + num); 
}

int main() 
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    Nsum(num , 0); 
    return 0;
}