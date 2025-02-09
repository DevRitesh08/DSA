#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (linear search)
// Time complexity is O(n^2) where n is the size of the array.
// space complexity is O(1) as we are not using any extra space.

int main()
{
    int arr[] = {1,2,3,6,5,9,8,1,2,3,6,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num;
    int count;
    for(int i = 0 ; i < n ; i++)
    {
        count = 0;
        num = arr[i];
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[j] == num)
            {
                count++;
            }
        }
        if(count == 1)// for rest of the elements count will be 2
        {
            cout<<"The number that appears once is : "<<num;
            break;
        }
    }
}



// Better Approach (hashing)
// Time complexity is O(3n) where n is the size of the array.
// space complexity is O(n) as we are using hash_array of size n+1.

// int main()
// {
//     int arr[] = {1,2,3,6,5,9,8,1,2,3,6,5,9};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int max_element = arr[0];

//     for(int i = 0 ; i < n ; i++)
//     {
//         max_element = max(max_element, arr[i]);
//     }

//     int hash_array[max_element + 1] = {0}; // as the hash_array starts from 0 to n , so the size of the hash_array is n+1

//     for(int i = 0 ; i < n ; i++) // tc O(n)
//     {
//         hash_array[arr[i]]++;
//     }

//     for(int i = 0 ; i < n ; i++) // tc O(n)
//     {
//         if(hash_array[i] == 1) // for rest of the elements count will be 2
//         {
//             cout<<"The number that appears once is : "<<i;
//             break;
//         }
//     }
// }


// Optimal Approach (XOR)
// Time complexity is O(n) where n is the size of the array.
// space complexity is O(1) as we are not using any extra space.


// int main()
// {
//     int arr[] = {1,2,3,6,5,9,8,1,2,3,6,5,9};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int xor1 = 0;
//     for(int i = 0 ; i < n ; i++)
//     {
//         xor1 = xor1 ^ arr[i];
//     }

//     cout<<"The number that appears once is : "<<xor1;

//     return 0;
// }
