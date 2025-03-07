// Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

// Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: (Linear Search)

// A simple approach is to iterate through the array and check for peak conditions. A peak is found if:
// (i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1]). If these conditions are met, return the index of the peak.


int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}





// Optimal Approach(Using Binary Search): 

// Since the array is not sorted, we can use binary search to find a peak more efficiently. The idea is to check the middle element and its neighbors. If the middle element is greater than both neighbors, it’s a peak. If the left neighbor is greater, search the left half; if the right neighbor is greater, search the right half. This reduces the time complexity to O(log N) .


//Algorithm (Binary Search for Peak Element):


// 1. Initialize two pointers:
    // low = 0
    // high = n - 1 (where n is the length of the array)

// 2. Binary Search Loop:
    // While low <= high:
        // 1. Compute the middle index: mid = low + (high - low) // 2
        // 2. Check if mid is a peak element:
            // If arr[mid] > arr[mid-1] (if mid > 0) and arr[mid] > arr[mid+1] (if mid < n-1), then mid is a peak. Return mid.
        // 3. If the left neighbor is greater, then peak must be on the left half:
            // Set high = mid - 1.
        // 4. If the right neighbor is greater, then peak must be on the right half:
            // Set low = mid + 1.
// 3. Return the peak index.


int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

// Time Complexity: O(logN), N = size of the given array.
// Reason: We are basically using binary search to find the minimum.




int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
