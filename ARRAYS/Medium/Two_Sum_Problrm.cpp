#include<bits/stdc++.h>
using namespace std;

// Brute force approach

// int main()
// {
//     int arr[] = {1,2,3,1,1,0,0,0,1,1,4,2,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k =3;

//     for(int i = 0 ; i < n ; i++ )
//     {
//         for(int j = i+1 ; j < n ; j++)
//         {
//             if(arr[i] + arr[j] == k)
//             {
//                 cout<<"indices : ["<<i<<","<<j<<"]"<<endl;
//             }
//         }
//     }
//     return 0;
// }

// Time Complexity: O(N^2) where N = size of the array.
// Space Complexity: O(1) as we are not using any extra space.


// Better Approach (Hashing)

// int main() {
//     vector<int> arr = {1,2,3,1,1,0,0,0,1,1,4,2,3};
//     int target = 3;
//     int n = arr.size();
//     unordered_map<int, vector<int>> mpp; // Maps a number to its indices.
//     bool pairFound = false;              // Flag to check if at least one pair was found.

//     for (int i = 0; i < n; i++) {
//         int num = arr[i];
//         int complement = target - num;
        
//         // If the complement is found, print all pairs immediately.
//         if (mpp.find(complement) != mpp.end()) {
//             for (int j : mpp[complement]) {
//                 cout << "Pair found: [" << j << ", " << i << "]" <<endl;
//                 pairFound = true;
//             }
//         }
//         // Store the current index for the current number.
//         mpp[num].push_back(i);
//     }

//     // If no pairs were printed, indicate that.
//     if (!pairFound) {
//         cout << "No pairs found that sum to " << target << "." <<endl;
//     }

//     return 0;
// }

// Time Complexity: O(N) where N = size of the array , but in the worst case, it can be O(N^2) if the hash function is not good.
// Space Complexity: O(N) as we are using a map data structure.



// Optimized Approach (two pointer approach)

int main()
{
    vector<int> arr = {1,2,3,1,1,0,0,0,1,1,4,2,3};
    int target = 3;
    int n = arr.size();
    int start = 0;
    int end = n-1;
    sort(arr.begin(), arr.end()); // time complexity of sorting is O(N*logN)
    while(start < end) // time complexity of this loop is O(N)
    {
        if(arr[start] + arr[end] == target)
        {
            cout<<"Pair found: ["<<start<<", "<<end<<"]"<<endl;
            start++;
            end--;
        }
        else if(arr[start] + arr[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return 0;
}

// Time Complexity: O(N*logN) where N = size of the array.
// Space Complexity: O(1) as we are not using any extra space.

// Brute-force and hashing approaches find all possible pairs, including those that might involve the same number at different positions.
// The two-pointer approach finds unique pairs and doesn't account for multiple occurrences of the same number unless explicitly handled.

// reasons explained below:

// 1. Sorting Changes the Original Indices
// In the brute-force and hashing approaches, the array remains unsorted, and you are directly comparing elements while retaining their original indices. However, in the optimized approach, you sort the array first, which rearranges the elements and loses the connection to their original indices.Now, when you're using the two-pointer approach on the sorted array, you're referring to the sorted indices rather than the original indices.
// 2. Skipping Duplicate Pairs
// In the optimized approach, when you find a pair that sums to the target, you increment start++ and decrement end-- immediately: This skips over duplicate values, which would otherwise form valid pairs in the brute-force or hashing approaches. For example, if multiple 1s and 2s exist in the array, the brute-force and hashing approaches will find all possible combinations, but the optimized approach will skip over them once a pair is found.