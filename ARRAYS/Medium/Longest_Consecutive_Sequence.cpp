
#include <bits/stdc++.h>
using namespace std;

// Brute force approach


bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

// Time Complexity: O(N2), N = size of the given array.
// Reason: We are using nested loops each running for approximately N times.

// Space Complexity: O(1), as we are not using any extra space to solve this problem.



// Better approach

// int longestSuccessiveElements(vector<int>&a) {
//     int n = a.size();
//     if (n == 0) return 0;

//     //sort the array:
//     sort(a.begin(), a.end());
//     int lastSmaller = INT_MIN;
//     int cnt = 0;
//     int longest = 1;

//     //find longest sequence:
//     for (int i = 0; i < n; i++) {
//         if (a[i] - 1 == lastSmaller) {
//             //a[i] is the next element of the
//             //current sequence.
//             cnt += 1;
//             lastSmaller = a[i];
//         }
//         else if (a[i] != lastSmaller) {
//             cnt = 1;
//             lastSmaller = a[i];
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;

// }

// Time Complexity: O(NlogN) + O(N), N = size of the given array.
// Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).

// Space Complexity: O(1), as we are not using any extra space to solve this problem.



// // Optimal approach


// int longestSuccessiveElements(vector<int>&a) {
//     int n = a.size();
//     if (n == 0) return 0;

//     //sort the array:
//     sort(a.begin(), a.end());
//     int lastSmaller = INT_MIN;
//     int cnt = 0;
//     int longest = 1;

//     //find longest sequence:
//     for (int i = 0; i < n; i++) {
//         if (a[i] - 1 == lastSmaller) {
//             //a[i] is the next element of the
//             //current sequence.
//             cnt += 1;
//             lastSmaller = a[i];
//         }
//         else if (a[i] != lastSmaller) {
//             cnt = 1;
//             lastSmaller = a[i];
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;

// }

// Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
// Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

// Space Complexity: O(N), as we are using the set data structure to solve this problem.

// Note: The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations. 

        // If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2). 
        // And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).



int main()
{
    vector<int> a = { 100 , 200 , 1 , 5 , 9 , 2 , 4 , 3};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
