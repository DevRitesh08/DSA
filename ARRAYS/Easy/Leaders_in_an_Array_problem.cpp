#include <bits/stdc++.h>  
using namespace std;



// Brute force approach to find leaders in an array

int main() 
{
    int arr[] = {10, 22, 6, 12, 7, 9, 5, 2};  // Leaders are 22, 12, 9, 5, 2
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) 
    {
        bool leader = true;  // Assume arr[i] is a leader
        
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] < arr[j]) // If any element on the right is greater, it's not a leader
            {  
                leader = false;
                break;
            }
        }

        if (leader)  // If it's still true, print the leader
            cout << arr[i] << " ";
    }
    return 0;
}

// Time complexity is O(N^2)
// Space complexity is O(1)



// Optimal approach (Reverse traversal approach)

// #include <bits/stdc++.h> 
// using namespace std;

// int main() {
//     int arr[] = {16, 17, 4, 3, 5, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);  

//     vector<int> ans;  
//     int max_element = INT_MIN;  

//     for (int i = n - 1; i >= 0; i--) {
//         if (arr[i] > max_element) {
//             ans.push_back(arr[i]);
//         }
//         max_element = max(max_element, arr[i]);
//     }

//     // Reverse to maintain order as found from right to left
//     sort(ans.begin(), ans.end());  // time complexity is O(N * logN)

//     cout << "The leader elements are: [";
//     for (int i = 0; i < ans.size(); i++) {  
//         cout << ans[i] << " ";
//     }
//     cout << "]" << endl;  

//     return 0;  
// }

//if sort function is not used then time coplexity will be O(N).
// Time complexity is O(N + N*logN) that boils down to O(N*logN) as in In big-O notation, we keep only the dominant term (the term that grows the fastest as n increases) , O(n log n) grows faster than O(n) for large n, so we drop the lower-order terms.
// hence , O(n + n log n) simplifies to O(n log n) because the O(n log n) term dominates.

// time comlexity of reverse function is O(N) while for sort function it is (N*logN) .

// Space complexity is O(N) , but that is not used to solve the problemk it is used to store the answer .

