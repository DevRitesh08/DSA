// Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.


#include <iostream>
using namespace std;


// Brute Force Approach :

bool canWePlace(vector<int> &stalls, int dist, int cows) 
{
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) 
    {
        if (stalls[i] - last >= dist) 
        {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) 
{
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++) 
    {
        if (canWePlace(stalls, i, k) == false) 
        {
            return (i - 1);
        }
    }
    return limit;
}

// Time Complexity: O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
// Reason: O(NlogN) for sorting the array. We are using a loop from 1 to max(stalls[])-min(stalls[]) to check all possible distances. Inside the loop, we are calling canWePlace() function for each distance. Now, inside the canWePlace() function, we are using a loop that runs for N times.





// Optimized Approach using binary search :

bool canWePlace(vector<int> &stalls, int dist, int cows) 
{
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) 
    {
        if (stalls[i] - last >= dist) 
        {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) 
{
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) 
        {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

// Time Complexity: O(NlogN) + O(Nlog(max(stalls[])-min(stalls[])))b ==> O(N*logN), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.




int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

