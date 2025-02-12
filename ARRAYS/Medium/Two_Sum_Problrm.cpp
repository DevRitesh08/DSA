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