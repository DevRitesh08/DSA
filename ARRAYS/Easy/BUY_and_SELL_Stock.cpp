#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach

int main()
{
    int arr[] = {7,3,5,2,4,7,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxProfit = 0 ;

    for(int i = 0 ; i < n ; i++) // Buying day
    {
        for(int j = i+1 ; j < n ; j++) // Selling day
        {
            if(arr[j] > arr[i] )  maxProfit = max(arr[j] - arr[i],maxProfit);
        }
    }

    cout<<"the maximum profit is : "<<maxProfit;
}

// Outer Loop (i): Represents the day on which we buy the stock.
// Inner Loop (j): Represents the day on which we sell the stock.
// The condition arr[j] > arr[i] ensures that we are selling at a higher price than we bought.
// maxProfit = max(arr[j] - arr[i], maxProfit);
    // Calculates the profit if we buy on day i and sell on day j.
    // Updates maxProfit if the new profit is greater.

// Time complexity is O(N^2)
// Space complexity is O(1)



// OPtimal Approach

// int main()
// {
//     int arr[] = {7,3,5,2,4,7,3,9};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int maxProfit = 0 ;
//     int minPrice = INT_MAX ;

//     for(int i = 0 ; i < n ; i++)
//     {
//         minPrice = min(minPrice, arr[i]);
//         maxProfit = max(maxProfit, arr[i] - minPrice);
//     }

//     cout<<"The maximum profit is : "<<maxProfit;
// }

// Time complexity is O(N)