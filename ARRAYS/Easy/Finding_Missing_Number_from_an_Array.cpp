#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach (linear search)
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int flag;

    for(int i = 1 ; i <= n ; i++)
    {
        flag = 0;
        for(int j = 0 ; j < n ;j++) // iterate from 0 to n
        {
            if(arr[j] == i)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            cout<<"Missing element is : "<<i;
        }
       
    }
}