#include<bits/stdc++.h>
using namespace std;



// Brute solution 

// Approach :

// Step 1: Find all possible permutations of elements present and store them.
// Step 2: Search input from all possible permutations.
// Step 3: Print the next permutation present right after it.

// Time complexity will be O(N!*N) , N represents the number of elements presents in input array , also for searching input arrays from all possible permutations will take N! . therefore , it has a very high time complexity of O(N!*N) , hence only tell the approach , but if asked to write algo  then refer to lecture 11 and 12 of recursion .




// Better Solution

// C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater permutation of the input.

// int main() 
// {
//     int arr[] = {1,3,2};
    
//     next_permutation(arr,arr + 3);// using in-built function of C++
    
//     cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
//     return 0;
// }

// Time Complexity: O(N) (worst case, when the entire array needs to be reversed).
// Space Complexity: O(1) (modifies the array in-place, no extra space used).



// Optimal Approach
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {1,3,2};
    int n = A.size(), ind = -1;

    // Find the breakpoint
    for (int i = n - 2; i >= 0; i--)
        if (A[i] < A[i + 1]) { ind = i; break; }

    if (ind == -1) { reverse(A.begin(), A.end()); }  
    else {
        for (int i = n - 1; i > ind; i--)
            if (A[i] > A[ind]) { swap(A[i], A[ind]); break; }
        reverse(A.begin() + ind + 1, A.end());
    }

    for (int num : A) cout << num << " ";
}
 
// time complexity is O(N) .
// space complexity is O(1) .