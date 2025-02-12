// Subarray --> Contiguous elements of an array.

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (generate all sub arrays and check the sum of each subarray)
// Time complexity is O(n^3) where n is the size of the array.
// space complexity is O(1) as we are not using any extra space.

int main()
{
    int arr[] = {1,2,3,1,1,0,0,0,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 3 ;
    int max_length = 0;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            int S = 0;
            for(int k = i ; k <= j ; k++)
            {
                S += arr[k];
            }
            if(S ==  sum)
            {
                max_length = max(max_length, j-i+1);
            }
        }
    }
    cout<<"The length of the longest subarray with the given sum is : "<<max_length;

    return 0;
}

// Optimized Brute force approach
// Time complexity is O(n^2) where n is the size of the array.
// space complexity is O(1) as we are not using any extra space.


// int main()
// {
//     int arr[] = {1,2,3,1,1,0,0,0,1,1,4,2,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int sum = 3 ;
//     int max_length = 0;

//     for(int i = 0 ; i < n ; i++)
//     {
//         int S = 0;
//         for(int j = i ; j < n ; j++)
//         {            
//             S += arr[j];
            
//             if(S ==  sum)
//             {
//                 max_length = max(max_length, j-i+1);
//             }
//         }
//     }
//     cout<<"The length of the longest subarray with the given sum is : "<<max_length;

//     return 0;
// }


// Better Approach (Hashing)

// int main()
// {
//     int arr[] = {1,2,3,1,1,0,0,0,1,1,4,2,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 3 ;

//     map <long , int > pre_sum_map ;
//     long sum = 0 ; 
//     int max_len = 0 ;

//     for(int i = 0 ; i < n ; i++)
//     {
//         sum += arr[i] ; 

//         if(sum == k)
//         {
//             max_len = max(max_len, i+1);
//         }
        
//          // calculate the sum of remaining part i.e. x-k:
//          long long rem = sum - k;

//          //Calculate the length and update maxLen:
//          if (pre_sum_map.find(rem) != pre_sum_map.end()) 
//          {
//              int len = i - pre_sum_map[rem];
//              max_len = max(max_len, len);
//          }
 
//          //Finally, update the map checking the conditions:
//          if (pre_sum_map.find(sum) == pre_sum_map.end()) 
//          {
//              pre_sum_map[sum] = i;
//          }
//     }

//     cout<<"The length of the longest subarray with the given sum is : "<<max_len;
    
//     return 0;
// }

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
// Space Complexity: O(N) as we are using a map data structure.




// Optimal Approach (Two Pointer Approach)

// int main()
// {
//     int arr[] = {1,2,3,1,1,0,0,0,1,1,4,2,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 3 ;
//     int left = 0 ;
//     int right = 0 ;
//     int sum = arr[0] ;
//     int max_len = 0 ;

//     while(right < n)
//     {
//         while(left <= right && sum > k) // if sum is greater than k then we will remove the elements from the left side and the other condition is that left should be less than or equal to right that means it is still a subarray.
//         {
//             sum -= arr[left];
//             left++;
//         }

//         if(sum == k)
//         {
//             max_len = max(max_len, right-left+1);
//         }

//         right++;
//         if(right < n)
//         {
//             sum += arr[right];
//         }
//     }

//     cout<<"The length of the longest subarray with the given sum is : "<<max_len;

//     return 0;
// }

// Time Complexity: O(2*N), where N = size of the given array.
// Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).

// Space Complexity: O(1) as we are not using any extra space.