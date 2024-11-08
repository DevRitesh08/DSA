// enter value of n : 4
// * * * * 
// * * * 
// * * 
// * 

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = n-i ; j > 0  ;j--)
        {
            cout<<"* ";
        }
        cout<<endl;
    } 
}


int main()
{
    int n;
    cout<<"enter value of n : ";
    cin>>n;
    pattern(n);
}