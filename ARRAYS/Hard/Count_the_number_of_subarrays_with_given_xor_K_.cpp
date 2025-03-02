#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

// Time Complexity: O(N^3) approx., where N = size of the array.
// Reason: We are using three nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.




// Better Approach

// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size(); //size of the given array.
//     int cnt = 0;

//     // Step 1: Generating subarrays:
//     for (int i = 0; i < n; i++) {
//         int xorr = 0;
//         for (int j = i; j < n; j++) {

//             //step 2:calculate XOR of all
//             // elements:
//             xorr = xorr ^ a[j];

//             // step 3:check XOR and count:
//             if (xorr == k) cnt++;
//         }
//     }
//     return cnt;
// }

// Time Complexity: O(N2), where N = size of the array.
// Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N2).

// Space Complexity: O(1) as we are not using any extra space.




// Optimal Approach Using Hash Map


// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size(); //size of the given array.
//     int xr = 0;
//     map<int, int> mpp; //declaring the map.
//     mpp[xr]++; //setting the value of 0.
//     int cnt = 0;

//     for (int i = 0; i < n; i++) {
//         // prefix XOR till index i:
//         xr = xr ^ a[i];

//         //By formula: x = xr^k:
//         int x = xr ^ k;

//         // add the occurrence of xr^k
//         // to the count:
//         cnt += mpp[x];

//         // Insert the prefix xor till index i
//         // into the map:
//         mpp[xr]++;
//     }
//     return cnt;
// }

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2). 

// Space Complexity: O(N) as we are using a map data structure.



int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
