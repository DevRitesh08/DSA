// enter value of n : 4
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 

#include<bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= i ;j++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int n;
    cout<<"enter value of n : ";
    cin>>n;
    pattern1(n);
}