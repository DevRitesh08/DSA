// Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
    // You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
    // Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.



#include <bits/stdc++.h>
using namespace std;


// Brute Force approach:

bool possible(vector<int> &arr, int day, int m, int k) 
{
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;

    // count the number of bouquets:
    for (int i = 0; i < n; i++) // Time Complexity: O(n), where 'n' is the number of elements in 'arr'.
    {
        if (arr[i] <= day) 
        {
            cnt++;
        }
        else 
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> arr, int k, int m) 
{
    long long val = (long long)m * k ; // can also do like this : long long val = m * 1ll * k * 1ll; here 1ll is used to convert m and k to long long.
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;

    for (int i = 0; i < n; i++) // Time Complexity: O(n), where 'n' is the number of elements in 'arr'.
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) // Time Complexity: O(maxi - mini + 1), where 'maxi' and 'mini' are the maximum and minimum elements in 'arr'.
    {
        if (possible(arr, i, m, k)) 
            return i;
    }
    return -1;
}

// Time Complexity: O(n) + O(maxi - mini + 1)*O(n) = O(n*(maxi - mini + 1)), where 'n' is the number of elements in 'arr' and 'maxi' and 'mini' are the maximum and minimum elements in 'arr'.
// Reason: We are running a loop to check our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).




// Optimal Approach(Using Binary Search): 


// bool possible(vector<int> &arr, int day, int m, int k) 
// {
//     int n = arr.size(); //size of the array
//     int cnt = 0;
//     int noOfB = 0;
//     // count the number of bouquets:
//     for (int i = 0; i < n; i++) // Time Complexity: O(n), where 'n' is the number of elements in 'arr'.
//     {
//         if (arr[i] <= day) 
//         {
//             cnt++;
//         }
//         else 
//         {
//             noOfB += (cnt / k);
//             cnt = 0;
//         }
//     }
//     noOfB += (cnt / k);
//     return noOfB >= m;
// }
// int roseGarden(vector<int> arr, int k, int m) 
// {
//     long long val = m * 1ll * k * 1ll;
//     int n = arr.size(); //size of the array
//     if (val > n) return -1; //impossible case.
//     //find maximum and minimum:
//     int mini = INT_MAX, maxi = INT_MIN;
//     for (int i = 0; i < n; i++) // Time Complexity: O(n), where 'n' is the number of elements in 'arr'.
//     {
//         mini = min(mini, arr[i]);
//         maxi = max(maxi, arr[i]);
//     }

//     //apply binary search:
//     int low = mini, high = maxi;
//     while (low <= high) // Time Complexity: O((log(maxi - mini))*n), where 'maxi' and 'mini' are the maximum and minimum elements in 'arr'and n is the number of elements in 'arr'.
//     {
//         int mid = (low + high) / 2;
//         if (possible(arr, mid, m, k)) // Time Complexity: O(n), where 'n' is the number of elements in 'arr'.
//         {
//             high = mid - 1;
//         }
//         else low = mid + 1;
//     }
//     return low;
// }

// Time Complexity: O(n) + O(n*(log(maxi - mini))) = O(n*(log(maxi - mini))), where 'n' is the number of elements in 'arr' and 'maxi' and 'mini' are the maximum and minimum elements in 'arr'.

// Reason: We are applying binary search on our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer ‘mid’, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).






int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}
