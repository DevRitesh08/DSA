#include<bits/stdc++.h>
using namespace std;

// Subarray --> only consecutive part of array

// Brute Force Approach

int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maximum = INT_MIN ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            int sum = 0 ;
            for(int k = i ; k < j ; k++)
            {
                sum += arr[k];
            }
            maximum = max (sum , maximum) ;
        }
    }

    cout<<"the maximum subarray sum is : "<<maximum;

    return 0;
}

// Time complexity is O(N^3)
// Space complexity is O(1)



// Better Approach

// int main()
// {
//     int arr[] = {-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int maximum = INT_MIN ;

//     for(int i = 0 ; i < n ; i++)
//     {
//         int sum = 0 ;

//         for(int j = i ; j < n ; j++)
//         {
//             sum += arr[j];
//             maximum = max (sum , maximum) ;
//         }
        
//     }

//     cout<<"the maximum subarray sum is : "<<maximum;

//     return 0;
// }

// Time Complexity is O(N^2)
// Space Complexity is O(1)



// Optimal Approach ( Kadane's Algorithm )

// int main()
// {
//     int arr[] = {-2,-3,4,-1,-2,1,5,-3};
//     // int arr[] = {-2,-3,-1,-2,-3};  // array to verify the empty sub-array case below
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int sum = 0 ;
//     int maximum = INT_MIN ;

//     for(int i = 0 ; i < n ; i++)
//     {
//         sum += arr[i] ;

//         if(sum > maximum)   maximum = sum ;

//         if(sum < 0)    sum = 0 ;
//     }

//     // if it is given in question that if the their is no subarray with sum < 0  then take an empty sub-array (which means sum is Zero)
//     if(sum < 0) maximum = 0 ;

//     cout<<"the maximum subarray sum is : "<<maximum;
// }

// Time complexity is O(N)
// Space complexity is O(1)


// Follow-up Question

// If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

// So, we will keep a track of the starting index inside the loop using a start variable.
// We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i.



// int main()
// {
//     int arr[] = {-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int sum = 0 ;
//     int maximum = INT_MIN ;

//     int start = 0;
//     int ansStart = -1, ansEnd = -1;

//     for(int i = 0 ; i < n ; i++)
//     {
//         if(sum == 0) start = i ; // starting index

//         sum += arr[i] ;

//         if(sum > maximum)  
//         {
//             maximum = sum ;
//             // they keep track of the sub-array
//             ansStart = start;
//             ansEnd = i;

//         }

//         if(sum < 0)    sum = 0 ;
//     }

//     //printing the subarray:
//     cout << "The subarray is: [";
    
//     for (int i = ansStart; i <= ansEnd; i++) 
//     {
//         cout << arr[i] << " ";
//     }
    
//     cout << "]"<<endl;

//     return 0 ;

// }

// Time complexity is still O(N) .
// Space complexity is still O(1) .