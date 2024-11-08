// here in back_tracking we can't use increment operators ++ , + etc in case of printing 1 to n numbers .

#include<bits/stdc++.h>
using namespace std ;

void f(int i , int num)
{
    if(i < 1)
        return ;

    f(i - 1 , num);
    cout<<i<<endl;
}

int main()
{
    int num;
    cout<<"enter a number : ";
    cin>>num;
    f(num , num);
}