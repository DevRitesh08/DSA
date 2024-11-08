#include<bits/stdc++.h>
using namespace std;

int Fibo(int n)
{
    if(n <= 1) return n ;// for n = 0 and n = 1
    int last = Fibo(n - 1);
    int slast = Fibo(n - 2);

    return last + slast ;
} 

int main()
{
    int n;
    cout<<"enter the Nth fibonacci number to find : ";
    cin>>n;
    cout<<n<<" fibonacci number is : "<<Fibo(n);
}

//fibo series -->1,1,2,3,5,8,........
// but if fibo series is asked from zero then instead of
// the function call Fibo(n) in main change it to Fibo(n - 1)