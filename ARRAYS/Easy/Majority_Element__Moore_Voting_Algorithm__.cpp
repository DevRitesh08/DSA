#include<bits/stdc++.h>
using namespace std;


// Brute force approach

int main()
{
    int arr[]= {1,2,3,1,2,3,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt , ans = -1;

    for(int i = 0 ; i < n ; i++) // selected element is v[i]
    {
        cnt = 0 ;
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[j] == arr[i]) // counting the frequency of v[i] 
            cnt++ ;
        }

        if(cnt > n/2)
        {
            ans = arr[i];
            break;
        }
            
    }

        if(ans != -1)
        {
            cout<<"the majority element is : "<<ans;
        }
        else
        {
            cout<<"no majority element is present !"<<endl;
        }

    return 0;
}

// Time complexity is O(N^2) .
// Space complexity is O(1) .



// Better approach (Hashing)

// int main()
// {
//     int arr[] = {1,2,3,1,2,3,3,3,3,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     map<int,int> mpp;

//      //storing the elements with its occurnce:
//     for (int i = 0; i < n; i++) 
//     {
//         mpp[arr[i]]++; // time complexity O(logN)
//     }

//     //searching for the majority element:
//     for (auto it : mpp) 
//     {
//         if (it.second > (n / 2))
//         {
//             cout<<"the majority element is : "<<it.first<<endl;
//             break;
//         }
//     }

//     return 0 ;
// }

// Time complexity is O(NlogN + N) .
// Space compexity is O(N) , because of unordered map .



// Optimal approach (Moore’s Voting Algorithm)

// int main()
// {
//     int arr[] = {1,2,3,1,2,3,3,3,3,3};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int count = 0 , element ; // count here doesn't store how many times a number is appearing .

//     for(int i = 0 ; i < n ; i++)
//     {

//         if(count == 0)
//         {
//             count = 1 ;
//             element = arr[i] ;
//         }
        
//         else if (element == arr[i])
//         {count++ ; }

//         else
//         count-- ;
//     }

//     //checking if the stored element
//     // is the majority element:
//     int cnt1 = 0;
//     for (int i = 0; i < n; i++) 
//     {
//         if (arr[i] == element) cnt1++;
//     }

//     if (cnt1 > (n / 2))
//     {
//         cout<<"the majority element is : "<<element<<endl ;
//     }

//     return 0;
// }

// Time complexity is O(2N)
// Space complexity is O(1)