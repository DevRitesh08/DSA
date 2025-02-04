#include<iostream>
using namespace std;

int main()
{
    int arr[]= {9,8,7,7,6,5,4,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ascending = 1;
    int descending = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i-1] < arr[i])
        {
            descending = 0;
        }
        else if(arr[i-1] > arr[i])
        {
            ascending = 0;
        }
    }

    if(ascending == 1) cout<<"array is sorted in ascending order"<<endl;
    else if(descending == 1) cout<<"array is sorted in descending order"<<endl;
    else cout<<"array is unsorted"<<endl;

    return 0;
}