// Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.



#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach :

int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) 
{
    vector<int> arr3;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) 
    {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < m) arr3.push_back(a[i++]);
    while (j < n) arr3.push_back(b[j++]);
    return arr3[k - 1];
}

// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We are using an extra array of size (m+n) to solve this problem.





// Better Approach (Optimized space)


// int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) 
// {
//     int ele = -1;
//     int cnt = 0; //counter
//     //apply the merge step:
//     int i = 0, j = 0;
//     while (i < m && j < n) 
//     {
//         if (a[i] < b[j]) 
//         {
//             if (cnt == k - 1) ele = a[i];
//             cnt++;
//             i++;
//         }
//         else 
//         {
//             if (cnt == k - 1) ele = b[j];
//             cnt++;
//             j++;
//         }
//     }

//     //copy the left-out elements:
//     while (i < m) 
//     {
//         if (cnt == k - 1) ele = a[i];
//         cnt++;
//         i++;
//     }
//     while (j < n) 
//     {
//         if (cnt == k - 1) ele = b[j];
//         cnt++;
//         j++;
//     }
//     return ele;
// }

// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(1), as we are not using any extra space to solve this problem.





// Optimal Approach (Using Binary Search) :


// int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) 
// {
//     if (m > n) return kthElement(b, a, n, m, k);

//     int left = k; //length of left half

//     //apply binary search:
//     int low = max(0, k - n), high = min(k, m);
//     while (low <= high) 
//     {
//         int mid1 = (low + high) >> 1;
//         int mid2 = left - mid1;
//         //calculate l1, l2, r1 and r2;
//         int l1 = INT_MIN, l2 = INT_MIN;
//         int r1 = INT_MAX, r2 = INT_MAX;
//         if (mid1 < m) r1 = a[mid1];
//         if (mid2 < n) r2 = b[mid2];
//         if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
//         if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

//         if (l1 <= r2 && l2 <= r1) 
//         {
//             return max(l1, l2);
//         }

//         //eliminate the halves:
//         else if (l1 > r2) high = mid1 - 1;
//         else low = mid1 + 1;
//     }
//     return 0; //dummy statement

// }

// Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
// Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).

// Space Complexity: O(1), as we are not using any extra space to solve this problem.





int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " <<
            kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
