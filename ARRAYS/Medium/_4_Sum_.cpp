#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Time Complexity: O(N4), where N = size of the array.
// Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.

// Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.


// Better Approach  (Using 3 loops and set data structure):

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     set<vector<int>> st;

//     //checking all possible quadruplets:
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             set<long long> hashset;
//             for (int k = j + 1; k < n; k++) {
//                 // taking bigger data type
//                 // to avoid integer overflow:
//                 long long sum = nums[i] + nums[j];
//                 sum += nums[k];
//                 long long fourth = target - sum;
//                 if (hashset.find(fourth) != hashset.end()) {
//                     vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 // put the kth element into the hashset:
//                 hashset.insert(nums[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
// Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.

// Space Complexity: O(2 * no. of the quadruplets)+O(N)
// Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).



// Optimal Approach (Using 2 pointers):

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     vector<vector<int>> ans;

//     // sort the given array:
//     sort(nums.begin(), nums.end());

//     //calculating the quadruplets:
//     for (int i = 0; i < n; i++) {
//         // avoid the duplicates while moving i:
//         if (i > 0 && nums[i] == nums[i - 1]) continue;
//         for (int j = i + 1; j < n; j++) {
//             // avoid the duplicates while moving j:
//             if (j > i + 1 && nums[j] == nums[j - 1]) continue;

//             // 2 pointers:
//             int k = j + 1;
//             int l = n - 1;
//             while (k < l) {
//                 long long sum = nums[i];
//                 sum += nums[j];
//                 sum += nums[k];
//                 sum += nums[l];
//                 if (sum == target) {
//                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                     ans.push_back(temp);
//                     k++; l--;

//                     //skip the duplicates:
//                     while (k < l && nums[k] == nums[k - 1]) k++;
//                     while (k < l && nums[l] == nums[l + 1]) l--;
//                 }
//                 else if (sum < target) k++;
//                 else l--;
//             }
//         }
//     }

//     return ans;
// }

// Time Complexity: O(N3), where N = size of the array.
// Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 

// Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).




int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1,3,3,3,3};
    int target = 12;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
