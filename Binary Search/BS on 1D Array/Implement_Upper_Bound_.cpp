// JUST REMOVE THE = SIGN FROM THE CONDITION IN THE IF CONDITION OF EACH APPROACH TO GET THE LOWER BOUND INSTEAD OF UPPER BOUND.


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (For Upper Bound):

int upperBound(vector<int> arr, int n, int x) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > x)  // Upper bound condition: find the first element > x
        {
            return i;
        }
    }
    return n;  // If no element > x is found, return n (size of the array)
}

// Time Complexity: O(N), where N = size of the given array.
// Reason: In the worst case, we have to travel the whole array. This is basically the time complexity of the linear search algorithm.

// Space Complexity: O(1) as we are using no extra space.

// Optimized Approach (Binary Search) for Upper Bound:

int upperBoundBinarySearch(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // Initially, answer is set to n (end of the array)

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;  // Update answer if we find a potential upper bound
            high = mid - 1;  // Look for a smaller index on the left
        } else {
            low = mid + 1;  // Look on the right side for a possible upper bound
        }
    }
    return ans;
}

// Time Complexity: O(logN), where N = size of the given array.
// Reason: We are using Binary Search, which has a logarithmic time complexity.

// Space Complexity: O(1) as we are using no extra space.

int main()
{
    vector<int> arr = {3, 5, 8, 9, 9, 9, 15, 19};
    int n = arr.size(), x = 9;
    
    // Using Brute Force Approach to find the upper bound
    int ind = upperBound(arr, n, x);
    cout << "The upper bound index is: " << ind << "\n";
    
    // Using Optimized Binary Search Approach for the upper bound
    int indBinarySearch = upperBoundBinarySearch(arr, n, x);
    cout << "The upper bound index (using binary search) is: " << indBinarySearch << "\n";

    return 0;
}





int main()
{
    vector<int> arr = {3, 5, 8, 9, 9, 9, 15, 19};
    int n = arr.size(), x = 9;
    int ind = upperBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}