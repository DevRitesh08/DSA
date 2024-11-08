#include<bits/stdc++.h>
using namespace std;

void rev(int i , int n ,int arr[])
{
    if( i >= n/2) return ;

    swap(arr[i] , arr[n - i - 1]);

    rev(i + 1 , n , arr);

}

int main()
{
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int arr[n];

    // input
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter "<< i + 1 <<" element of array : ";
        cin>>arr[i];
    }

    rev(0,n,arr);

    // print
    for(int i = 0 ; i < n ; i++)
    {
       cout<< arr[i] <<" ";
    }   

    return 0 ;
}