#include<bits/stdc++.h>
using namespace std ;
void f(int n)
{
    if(n < 1)
        return ;

    cout<<n<<endl;
    n--;
    f(n);
}
int main()
{
    int n;
    cout<<"enter a number : ";
    cin>>n;
    f(n);
}