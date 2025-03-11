// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach :

int missingK(vector < int > vec, int n, int k) 
{
    for (int i = 0; i < n; i++) 
    {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}

// Time Complexity: O(N).





// Optimized Approach using Binary Search:

// int missingK(vector < int > vec, int n, int k) 
// {
//     int low = 0, high = n - 1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int missing = vec[mid] - (mid + 1);
//         if (missing < k) 
//         {
//             low = mid + 1;
//         }
//         else 
//         {
//             high = mid - 1;
//         }
//     }
//     return k + high + 1;
// }

// Time Complexity: O(log(N)).





int main()
{
    vector<int> vec = {2, 3, 4, 7, 11};
    int n = 5, k = 5;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

