// enter value of n : 5
// 1  2  3  4  5  
// 1  2  3  4  
// 1  2  3  
// 1  2  
// 1 

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        //int x = 1;
        //for(int j = n-i ; j > 0  ;j--) 
        for (int j=1 ; j <= n-i ;j++)
        {
            //cout<< x++ <<"  ";
            cout<< j <<" ";
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