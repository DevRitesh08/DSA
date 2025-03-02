
#include<bits/stdc++.h>
using namespace std;


// Brute Force Approach :

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

// Time Complexity: O(N3)
// Reason: We are using 3 nested loops for finding all possible subarrays and their product.

// Space Complexity: O(1)





// Better Approach :

// int maxProductSubArray(vector<int>& nums) {
//     int result = nums[0];
//     for(int i=0;i<nums.size()-1;i++) {
//         int p = nums[i];
//         for(int j=i+1;j<nums.size();j++) {
//            result = max(result,p);
//            p *= nums[j];
//         }
//         result = max(result,p);//manages (n-1)th term 
//     }
//     return result;
// }

// Time Complexity: O(N2)
// Reason: We are using two nested loops

// Space Complexity: O(1)





// Optimal Approach : (based on observation)


// int maxProductSubArray(vector<int> &arr) {
//     int n = arr.size(); //size of array.

//     int pre = 1, suff = 1;
//     int ans = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         if (pre == 0) pre = 1;
//         if (suff == 0) suff = 1;
//         pre *= arr[i];
//         suff *= arr[n - i - 1];
//         ans = max(ans, max(pre, suff));
//     }
//     return ans;
// }

// Time Complexity: O(N), N = size of the given array.
// Reason: We are using a single loop that runs for N times.

// Space Complexity: O(1) as No extra data structures are used for computation.





// Optimal Approach : (based on kadane's algorithm)

// int maxProductSubArray(vector<int>& nums) {
//     int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
//     for(int i=1;i<nums.size();i++) {
//         int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
//         prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
//         prod1 = temp;
        
//         result = max(result,prod1);
//     }
    
//     return result;
// }

// Time Complexity: O(N)
// Reason: A single iteration is used.

// Space Complexity: O(1)





int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}
