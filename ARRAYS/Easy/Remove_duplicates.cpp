#include<bits/stdc++.h>
using namespace std;

// brute force approach

// int main()
// {
//     int arr[] = {1,2,2,3,4,4,5,6,7,7,8,9};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     set <int> s;
//     for(int i = 0; i < n; i++)
//     {
//         s.insert(arr[i]); // time complexity of insert is O(logn)
//     }
    
//     // printing the set

//     for(auto i = s.begin(); i != s.end(); i++)
//     {
//         cout<<*i<<" ";
//     }
// }

// Time complexity of this approach is O(nlogn) because of the set data structure.
// Space complexity of this approach is O(n) because of the set data structure.

// Optimal approach(2 pointer approach)

int main()
{
    int arr[] = {1,2,2,3,4,4,5,6,7,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    for(int j = 1; j < n ; j++)
    {
        if(arr[j] != arr[i])
        {
            arr[i+1] = arr[j];
            i++;
        }
    }
    
    // array printing
    for(int k = 0; k <= i; k++)
    {
        cout<<arr[k]<<" ";
    }

}
