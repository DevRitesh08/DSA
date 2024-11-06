#include<bits/stdc++.h>
using namespace std ;
void f(int i , int num)
{
    if(num > i)
        return ;

    cout<<num<<endl;
    num++;
    f(i,num);
}
int main()
{
    int i;
    cout<<"enter a number : ";
    cin>>i;
    int num = 1 ;
    f(i,num);
}