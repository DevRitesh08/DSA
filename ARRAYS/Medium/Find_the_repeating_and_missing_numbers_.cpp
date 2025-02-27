#include<bits/stdc++.h>
using namespace std;


// Brute Force Approach:

// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,9,9};
//     int n = sizeof(arr)/sizeof(arr[0]); // size of the array
//     int repeating = -1, missing = -1;

//     //Find the repeating and missing number:
//     for (int i = 1; i <= n; i++) 
//     {
//         //Count the occurrences:
//         int cnt = 0;
//         for (int j = 0; j < n; j++) 
//         {
//             if (arr[j] == i) cnt++;
//         }

//         if (cnt == 2) repeating = i;
//         else if (cnt == 0) missing = i;

//         if (repeating != -1 && missing != -1)
//             break;
//     }

//     cout <<"The repeating number is : "<<repeating <<endl<<"The missing number is : "<< missing << endl;
//     return 0;
// }

// Time Complexity: O(n^2), where n is the size of the given array.
// Space Complexity: O(1) as we are not using any extra space.



// Better Approach: (Using Hashing)

// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,9,9};
//     int n = sizeof(arr)/sizeof(arr[0]); // size of the array
//     int repeating = -1, missing = -1;
//     int hash[n+1] = {0};

//     // Count the occurrences:
//     for(int i = 0 ; i < n ; i++)
//     {
//         hash[arr[i]]++;
//     }

//     // Find the repeating and missing number:
//     for(int i = 1 ; i <= n ; i++)
//     {
//         if(hash[i] == 2) repeating = i;
//         else if(hash[i] == 0) missing = i;

//         if(repeating != -1 && missing != -1)
//             break;
//     }

//     cout <<"The repeating number is : "<<repeating <<endl<<"The missing number is : "<< missing << endl;
//     return 0;
// }

// Time complexity is O(2N) ~ O(N) and space complexity is O(N) as we are using an extra array of size n+1.



// Optimal Approach: (Using Mathematics)

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,9};
    long long n = sizeof(arr)/sizeof(arr[0]); // size of the array
   // Find Sn and S2n:
   long long SN = (n * (n + 1)) / 2;
   long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

   // Calculate S and S2:
   long long S = 0, S2 = 0;
   for (int i = 0; i < n; i++) {
       S += arr[i];
       S2 += (long long)arr[i] * (long long)arr[i];
   }

   //S-Sn = X-Y:
   long long val1 = S - SN;

   // S2-S2n = X^2-Y^2:
   long long val2 = S2 - S2N;

   //Find X+Y = (X^2-Y^2)/(X-Y):
   val2 = val2 / val1;

   //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
   // Here, X-Y = val1 and X+Y = val2:
   long long x = (val1 + val2) / 2;
   long long y = x - val1;
    cout <<"The repeating number is : "<<x <<endl<<"The missing number is : "<< y << endl;

    return 0;
}

// Time Complexity: O(N), where N = the size of the given array.
// Space Complexity: O(1) as we are not using any extra space to solve this problem.




// Optimal Approach: (Using XOR)