#include <bits/stdc++.h>
using namespace std;


// - We solve the problem using the lower-bound algorithm, a modified Binary Search.
// - Binary Search reduces the search space by eliminating half based on a condition.
// - The goal is to find the correct position or the existing position of the target number.
// - If the element is absent, find the nearest greater element (i.e., arr[ind] >= x).
// - The lower-bound algorithm returns the target's position if present or the nearest greater element.



int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// Time Complexity: O(logN), where N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.

// Space Complexity: O(1) as we are using no extra space.


int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}