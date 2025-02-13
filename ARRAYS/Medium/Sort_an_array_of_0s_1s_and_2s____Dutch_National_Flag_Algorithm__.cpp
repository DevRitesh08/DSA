#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach

// Sorting ( even if it is not the expected solution here but it can be considered as one of the approaches). Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing order.

// Time Complexity: O(N*logN)
// Space Complexity: O(N)


//Better Approach

// int main()
// {
//     int arr[] = {0,1,2,1,0,1,2,0};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int cnt0 = 0 , cnt1 = 0 , cnt2 = 0 ;

//     // fetching the number of occurrences of 0 , 1 and 2 .
//     for(int i = 0 ; i < n ; i++) // time complexity --> O(N)
//     {
//         if(arr[i] == 0)   cnt0 ++;
//         else if(arr[i] == 1) cnt1 ++;
//         else   cnt2 ++;
//     }

//     // Now overwriting the array ( Time complexity O(N) )
//     for(int i = 0 ; i < cnt0 ; i++)    arr[i] = 0 ;
//     for(int i = cnt0 ; i < cnt0 + cnt1 ; i++)    arr[i] = 1 ;
//     for(int i = cnt0 + cnt1 ; i < n ; i++)    arr[i] = 2 ;


//     // printing array not part of algo
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<<arr[i]<<"  ";
//     }

//     return 0 ;
// }
// Time complexity is O(2N)
// Space complexity is O(1)


// Optimal approach ( Dutch National Flag Algorithm )

int main()
{
    int arr[] = {0,1,2,1,0,1,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0 , mid = 0 , high = n-1 ;

    while( mid <= high ) // Time complexity is O(N) ,  as in each iteration only one element is sorting .
    {
        if(arr[mid] == 0)
        {
            swap(arr[low] , arr[mid]);// Time Complexity is O(1)
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid] , arr[high]);
            high--;
        }
    }

    // printing sorted array
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}

// Time complexity is O(N)
// Space Complexity is O(1)