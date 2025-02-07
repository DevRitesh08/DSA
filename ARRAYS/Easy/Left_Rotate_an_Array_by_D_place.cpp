#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d ;
    cout<<"enter the D : ";
    cin>>d;
    d = d % n ;
    int temp[d];
    // insertion of elements that are to be rotated in the temp array , its time complexity is O(d)
    for(int i = 0 ; i < d ; i++)
    {
        temp[i] = arr[i] ; 
    }
    // now shifting the elements of the array to the left , its time complexity is O(n-d)
    for(int i = d ; i < n ; i++)
    {
        arr[i-d] = arr[i];
    }
    // now inserting the elements of the temp array to the last of the array , its time complexity is O(d)
    for(int i = n-d ; i<n ; i++)
    {
        arr[i] = temp[i-(n-d)];
    }

    // printing the array , not part of the algorithm
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }

}