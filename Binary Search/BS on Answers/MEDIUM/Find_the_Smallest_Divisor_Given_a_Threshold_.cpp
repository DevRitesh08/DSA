
#include <bits/stdc++.h>
using namespace std;



// Brute Force Approach

int smallestDivisor(vector<int>& arr, int limit) 
{
    int n = arr.size(); //size of array.
    //Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    //Find the smallest divisor:
    for (int d = 1; d <= maxi; d++) 
    {
        //Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++) 
        {
            sum += ceil((double)(arr[i]) / (double)(d)); // ceil function is used to round up the value , its TC is O(1).  
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}

// Time Complexity: o(n) + O(N * log(max(arr))) ==> O(N * log(max(arr)))





// Optimized solution using Binary Search:


// int sumByD(vector<int> &arr, int div) 
// {
//     int n = arr.size(); //size of array
//     //Find the summation of division values:
//     int sum = 0;
//     for (int i = 0; i < n; i++) 
//     {
//         sum += ceil((double)(arr[i]) / (double)(div));
//     }
//     return sum;
// }

// int smallestDivisor(vector<int>& arr, int limit) 
// {
//     int n = arr.size();
//     if (n > limit) return -1;
//     int low = 1, high = *max_element(arr.begin(), arr.end()); // Tc of max_element is O(n).

//     //Apply binary search:
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;
//         if (sumByD(arr, mid) <= limit) 
//         {
//             high = mid - 1;
//         }
//         else 
//         {
//             low = mid + 1;
//         }
//     }
//     return low;
// }

// Time Complexity: o(N) + O(N * log(max(arr))) ==> O(N * log(max(arr)))




int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
