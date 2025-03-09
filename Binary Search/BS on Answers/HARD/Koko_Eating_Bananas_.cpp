// Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile    has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

    // Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
    // Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.



#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (linear search) :

// The extremely naive approach is to check all possible answers from 1 to max(a[]). The minimum number for which the required time <= h, is our answer.


int findMax(vector<int> &v) 
{
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) // O(N)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) 
{
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) // O(N)
    {
        totalH += ceil((double)(v[i]) / (double)(hourly));
        // The ceil() function in C++ (from the <cmath> library) returns the smallest integer greater than or equal to a given number.
        // Behavior:
            // If x is already an integer, ceil(x) returns x as it is.
            // If x is a decimal, ceil(x) rounds it up to the next integer.
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) 
{
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) // O(maxi)*O(N)
    {
        int reqTime = calculateTotalHours(v, i);// this function will take O(N) time , so the total time complexity will be O(maxi*N)
        if (reqTime <= h) 
        {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}

// time complexity : O(N)+O(maxi×N)= O(maxi×N)





// Optimized Approach (Binary Search) :


// int findMax(vector<int> &v) 
// {
//     int maxi = INT_MIN;
//     int n = v.size();
//     //find the maximum:
//     for (int i = 0; i < n; i++) // O(N)
//     {
//         maxi = max(maxi, v[i]);
//     }
//     return maxi;
// }

// int calculateTotalHours(vector<int> &v, int hourly) 
// {
//     int totalH = 0;
//     int n = v.size();
//     //find total hours:
//     for (int i = 0; i < n; i++) // O(N)
//     {
//         totalH += ceil((double)(v[i]) / (double)(hourly));
//     }
//     return totalH;
// }

// int minimumRateToEatBananas(vector<int> v, int h) 
// {
//     int low = 1, high = findMax(v);

//     //apply binary search:
//     while (low <= high) // O(log(maxi)) * O(N)
//     {
//         int mid = (low + high) / 2;
//         int totalH = calculateTotalHours(v, mid); // this function will take O(N) time , so the total time complexity will be O(log(maxi)*N)
//         if (totalH <= h) 
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

// O(n)+O(log(max(v)))×O(n)=O(nlog(max(v))) where n is the size of the vector v.







int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
