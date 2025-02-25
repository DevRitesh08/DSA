#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int solve( vector<int>& arr) 
{
    int n = arr.size();
    int maxLen = 0;

    // Traverse all possible subarrays
    for (int i = 0; i < n; ++i) 
    {
        int sum = 0;
        for (int j = i ; j < n; ++j) 
        {
            sum += arr[j];
            if (sum == 0) 
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}



// Optimal Approach Using Prefix Sum and Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

// int solve( vector<int>& arr) 
// {
//     unordered_map<int, int> sumIndexMap;
//     int sum = 0;
//     int maxLen = 0;

//     for (int i = 0; i < arr.size(); ++i) 
//     {
//         sum += arr[i];

//         if (sum == 0) {
//             maxLen = i + 1;
//         } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
//             maxLen = max(maxLen, i - sumIndexMap[sum]);
//         } else {
//             sumIndexMap[sum] = i;
//         }
//     }
//     return maxLen;
// }

int main() {
    vector<int> arr = {1, 2, -2, 4, -4};
    cout << "Length of the longest subarray with sum zero : " << solve(arr) << endl;

    return 0;
}
