// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach: (Linear Search)


int findMin(vector<int>& arr) 
{
    int n = arr.size(); // size of the array.
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) 
    {
        // Always keep the minimum.
        mini = min(mini, arr[i]);
    }
    return mini;
}

// Time Complexity: O(N), N = size of the given array.
// Reason: We have to iterate through the entire array to check if the target is present in the array.





// Optimal Approach(Using Binary Search): 

// int findMin(vector<int>& arr) 
// {
//     int low = 0, high = arr.size() - 1;
//     int ans = INT_MAX;
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;

//         //if left part is sorted:
//         if (arr[low] <= arr[mid]) 
//         {
//             // keep the minimum:
//             ans = min(ans, arr[low]);

//             // Eliminate left half:
//             low = mid + 1;
//         }
//         else 
//         { //if right part is sorted:

//             // keep the minimum:
//             ans = min(ans, arr[mid]);

//             // Eliminate right half:
//             high = mid - 1;
//         }
//     }
//     return ans;
// }

// Time Complexity: O(logN), N = size of the given array.
// Reason: We are basically using binary search to find the minimum.





// Further Optimization(Using Binary Search):

// int findMin(vector<int>& arr) 
// {
//     int low = 0, high = arr.size() - 1;
//     int ans = INT_MAX;
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;
//         //search space is already sorted
//         //then arr[low] will always be
//         //the minimum in that search space:
//         if (arr[low] <= arr[high]) 
//         {
//             ans = min(ans, arr[low]);
//             break;
//         }

//         //if left part is sorted:
//         if (arr[low] <= arr[mid]) 
//         {
//             // keep the minimum:
//             ans = min(ans, arr[low]);

//             // Eliminate left half:
//             low = mid + 1;
//         }
//         else 
//         { //if right part is sorted:

//             // keep the minimum:
//             ans = min(ans, arr[mid]);

//             // Eliminate right half:
//             high = mid - 1;
//         }
//     }
//     return ans;
// }

// Time Complexity: O(logN), N = size of the given array.
// Reason: We are basically using binary search to find the minimum. 




int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}