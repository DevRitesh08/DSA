// enter the value of n : 4
// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4


#include <bits/stdc++.h>
using namespace std ;

void pattern(int n)
{
    for(int i = 0 ; i < 2*n - 1  ; i++)
    {
        for(int j = 0 ; j < 2*n - 1 ;j++)
        {
            int top = i ;
            int left = j ;
            int right = (2*n - 2) - j ; 
            int down = (2*n - 2) - i ;
            cout<<( n - min(min( top , down ) , min(left  , right)))<<" " ;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    pattern(n);
}