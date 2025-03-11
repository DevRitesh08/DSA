// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
    // The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
    // Find out the least-weight capacity so that you can ship all the packages within 'd' days.

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach:


int findDays(vector<int> &weights, int cap) 
{
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) 
    {
        if (load + weights[i] > cap) 
        {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else 
        {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) 
{
    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end()); // TC of max_element is O(n).
    int sum = accumulate(weights.begin(), weights.end(), 0); // TC of accumulate is O(n).

    for (int i = maxi; i <= sum; i++) 
    {
        if (findDays(weights, i) <= d) 
        {
            return i;
        }
    }
    //dummy return statement:
    return -1;
}

// Time Complexity: O(N * ( max(arr) - sum(arr) +  1 ) .





// Optimized Approach using Binary Search:

// int findDays(vector<int> &weights, int cap) 
// {
//     int days = 1; //First day.
//     int load = 0;
//     int n = weights.size(); //size of array.
//     for (int i = 0; i < n; i++) 
//     {
//         if (load + weights[i] > cap) 
//         {
//             days += 1; //move to next day
//             load = weights[i]; //load the weight.
//         }
//         else 
//         {
//             //load the weight on the same day.
//             load += weights[i];
//         }
//     }
//     return days;
// }

// int leastWeightCapacity(vector<int> &weights, int d) 
// {
//     //Find the maximum and the summation:
//     int low = *max_element(weights.begin(), weights.end());
//     int high = accumulate(weights.begin(), weights.end(), 0);
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;
//         int numberOfDays = findDays(weights, mid);
//         if (numberOfDays <= d) 
//         {
//             //eliminate right half
//             high = mid - 1;
//         }
//         else 
//         {
//             //eliminate left half
//             low = mid + 1;
//         }
//     }
//     return low;
// }

// Time Complexity: O(N * log(max(arr) - sum(arr) + 1 ) ) .




int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
