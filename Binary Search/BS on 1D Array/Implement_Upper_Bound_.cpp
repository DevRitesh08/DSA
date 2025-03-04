// JUST REMOVE THE = SIGN FROM THE CONDITION IN THE IF CONDITION OF EACH APPROACH TO GET THE UPPER BOUND INSTEAD OF LOWER BOUND.



#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach:

int upperBound(vector<int> arr, int n, int x) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > x) 
        {
            // upper bound found:
            return i;
        }
    }
    return n;
}

// Time Complexity: O(N), where N = size of the given array.
// Reason: In the worst case, we have to travel the whole array. This is basically the time complexity of the linear search algorithm.

// Space Complexity: O(1) as we are using no extra space.





// Optimized Approach:

// int upperBound(vector<int> arr, int n, int x) {
//     int low = 0, high = n - 1;
//     int ans = n;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         // maybe an answer
//         if (arr[mid] > x) {
//             ans = mid;
//             //look for smaller index on the left
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1; // look on the right
//         }
//     }
//     return ans;
// }

// Time Complexity: O(logN), where N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.

// Space Complexity: O(1) as we are using no extra space.





// STl Approach:

// int upperBound(vector<int> arr, int n, int x) 
// {
//     auto it = upper_bound(arr.begin(), arr.end(), x); // Time Complexity: O(logN)
//     return it - arr.begin();
// }





int main()
{
    vector<int> arr = {3, 5, 8, 9, 9, 9, 15, 19};
    int n = arr.size(), x = 9;
    int ind = upperBound(arr, n, x);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}