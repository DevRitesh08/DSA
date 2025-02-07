#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int key ;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the key to find from the array : ";
    cin>>key;
    int count = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(key == arr[i])
        {
            cout<<key<<"  is present at "<<i+1<<"th place in an array"<<endl;
            count = 1 ;
            break ;
        }

    }
    if(count == 0 )
        cout<<key<<"  is not present in the given array";
}