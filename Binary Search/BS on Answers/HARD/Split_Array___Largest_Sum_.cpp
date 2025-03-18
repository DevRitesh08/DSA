// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.



#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach :

int countPartitions(vector<int> &a, int maxSum) 
{
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (subarraySum + a[i] <= maxSum) 
        {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else 
        {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) 
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    for (int maxSum = low; maxSum <= high; maxSum++) 
    {
        if (countPartitions(a, maxSum) == k)
            return maxSum;
    }
    return low;
}

// Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPartitions() function for each number. Now, inside the countPartitions() function, we are using a loop that runs for N times.





// Optimized Approach using binary search :

// int countPartitions(vector<int> &a, int maxSum) 
// {
//     int n = a.size(); //size of array.
//     int partitions = 1;
//     long long subarraySum = 0;
//     for (int i = 0; i < n; i++) {
//         if (subarraySum + a[i] <= maxSum)
//         {
//             //insert element to current subarray
//             subarraySum += a[i];
//         }
//         else 
//         {
//             //insert element to next subarray
//             partitions++;
//             subarraySum = a[i];
//         }
//     }
//     return partitions;
// }

// int largestSubarraySumMinimized(vector<int> &a, int k) 
// {
//     int low = *max_element(a.begin(), a.end());
//     int high = accumulate(a.begin(), a.end(), 0);
//     //Apply binary search:
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;
//         int partitions = countPartitions(a, mid);
//         if (partitions > k) 
//         {
//             low = mid + 1;
//         }
//         else 
//         {
//             high = mid - 1;
//         }
//     }
//     return low;
// }

// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPartitions() function for the value of ‘mid’. Now, inside the countPartitions() function, we are using a loop that runs for N times.







int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}