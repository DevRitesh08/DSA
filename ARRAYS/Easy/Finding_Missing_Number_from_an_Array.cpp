#include<bits/stdc++.h>
using namespace std;



// //Brute Force Approach (linear search)
// //Time complexity is O(n^2) where n is the size of the array.
// //space complexity is O(1) as we are not using any extra space.


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

    return 0;
}



// Better Approach (hashing)
//Time complexity is O(2n) where n is the size of the array.
//space complexity is O(n) as we are using hash_array of size n+1.


// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,10};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int hash_array[n + 1] = {0}; // as the hash_array starts from 0 to n , so the size of the hash_array is n+1

//     // hash_array is used to keep track of the elements of the array arr which are present in the array .
//     for(int i = 0 ; i < n-1 ; i++) // tc O(n)
//     {
//         hash_array[arr[i]] = 1;
//     }
    
//     //Printing the missing element
//     for(int i = 1 ; i <= n ; i++) // tc O(n)
//     {
//         if(hash_array[i] == 0)
//         {
//             cout<<"Missing element is : "<<i;
//         }
//     }

//     return 0;
// }

// Optimal approach ( sum of natural numbers )
// time complexity is O(n) where n is the size of the array.
// space complexity is O(1) as we are not using any extra space.


// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int m = n + 1;                // Total numbers including the missing one
//     int T_Sum = m * (m + 1) / 2;    // Sum of first m natural numbers
    
//     int sum = 0;                  // Initialize sum to 0
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];            // Sum of elements in the array
//     }

//     cout << "The missing number is: " << T_Sum - sum << endl;

//     return 0;
// }



// Optimal approach (XOR)
//Time complexity is O(n) where n is the size of the array.
//space complexity is O(1) as we are not using any extra space.

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int xor1 = 0;
//     int xor2 = 0;
//     for(int i = 0 ; i < n ; i++)
//     {
//         xor1 = xor1 ^ arr[i];
//     }

//     for(int i = 1 ; i <= n+1 ; i++)
//     {
//         xor2 = xor2 ^ i;
//     }

//     cout<<"Missing element is : "<<(xor1 ^ xor2);

//     return 0;
// }


// but it has a time complexity of O(2n) because of two loops and space complexity of O(1) .
// now we can optimize it to O(n) time complexity and O(1) space complexity by using the below approach.

// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int xor1 = 0;  // To XOR all elements in the array
//     int xor2 = 0;  // To XOR all numbers from 1 to n+1

//     for (int i = 0; i < n; i++) {
//         xor1 ^= arr[i];     // XOR of array elements
//         xor2 ^= (i + 1);    // XOR of numbers from 1 to n
//     }

//     xor2 ^= (n + 1);        // XOR with (n+1) to include the last number in the range

//     cout << "Missing element is: " << (xor1 ^ xor2) << endl;

//     return 0;
// }

// now the time complexity is O(n) and space complexity is O(1) .