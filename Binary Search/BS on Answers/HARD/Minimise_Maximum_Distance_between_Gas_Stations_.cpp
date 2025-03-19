// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.



#include <bits/stdc++.h>
using namespace std;


// // Brute Force Approach :

long double minimiseMaxDistance(vector<int> &arr, int k) 
{
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) 
    {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) 
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) 
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) 
    {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength =
            diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

// Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations to be placed.
// Reason: O(k*n) to insert k gas stations between the existing stations with maximum distance. Another O(n) for finding the answer i.e. the maximum distance.





// Better Approach(Using Heap): 

// long double minimiseMaxDistance(vector<int> &arr, int k) 
// {
//     int n = arr.size(); //size of array.
//     vector<int> howMany(n - 1, 0);
//     priority_queue<pair<long double, int>> pq;

//     //insert the first n-1 elements into pq
//     //with respective distance values:
//     for (int i = 0; i < n - 1; i++) 
//     {
//         pq.push({arr[i + 1] - arr[i], i});
//     }

//     //Pick and place k gas stations:
//     for (int gasStations = 1; gasStations <= k; gasStations++) 
//     {
//         //Find the maximum section
//         //and insert the gas station:
//         auto tp = pq.top();
//         pq.pop();
//         int secInd = tp.second;

//         //insert the current gas station:
//         howMany[secInd]++;

//         long double inidiff = arr[secInd + 1] - arr[secInd];
//         long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
//         pq.push({newSecLen, secInd});
//     }

//     return pq.top().first;
// }

// Time Complexity: O(nlogn + klogn),  n = size of the given array, k = no. of gas stations to be placed.
// Reason: Insert operation of priority queue takes logn time complexity. O(nlogn) for inserting all the indices with distance values and O(klogn) for placing the gas stations.

// Space Complexity: O(n-1)+O(n-1)
// Reason: The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue





// Optimal Approach(Using Binary Search): 


// int numberOfGasStationsRequired(long double dist, vector<int> &arr) 
// {
//     int n = arr.size(); // size of the array
//     int cnt = 0;
//     for (int i = 1; i < n; i++) 
//     {
//         int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
//         if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) 
//         {
//             numberInBetween--;
//         }
//         cnt += numberInBetween;
//     }
//     return cnt;
// }

// long double minimiseMaxDistance(vector<int> &arr, int k) 
// {
//     int n = arr.size(); // size of the array
//     long double low = 0;
//     long double high = 0;

//     //Find the maximum distance:
//     for (int i = 0; i < n - 1; i++) 
//     {
//         high = max(high, (long double)(arr[i + 1] - arr[i]));
//     }

//     //Apply Binary search:
//     long double diff = 1e-6 ;
//     while (high - low > diff) 
//     {
//         long double mid = (low + high) / (2.0);
//         int cnt = numberOfGasStationsRequired(mid, arr);
//         if (cnt > k) 
//         {
//             low = mid;
//         }
//         else 
//         {
//             high = mid;
//         }
//     }
//     return high;
// }

// Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.
// Reason: We are applying binary search on the answer space. For every possible answer, we are calling the function numberOfGasStationsRequired() that takes O(n) time complexity. And another O(n) for finding the maximum distance initially.

// Space Complexity: O(1) as we are using no extra space to solve this problem.





int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
