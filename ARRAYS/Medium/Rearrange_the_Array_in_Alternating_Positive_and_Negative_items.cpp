#include<bits/stdc++.h>
using namespace std;

// Variety 1 is where number of positive numbers are equal to the number of negative numbers .

// Brute force approach 

// int main()
// {
//     int arr[] = {1,6,7,8,3,-9,-6,-2,-4,-5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int parr[n/2];
//     int narr[n/2];

//     for(int i = 0 , j = 0 , k = 0 ; i < n ; i++)
//     {
//         if(arr[i] >= 0) parr[j++] = arr[i] ;
        
//         if(arr[i] < 0) narr[k++] = arr[i] ;

//     }

//     for(int i = 0 ; i < n/2 ; i++)
//     {
//         arr[2*i] = parr[i];
//         arr[2*i + 1] = narr[i];
//     }

//     // printing the array
//     cout<<"[ ";
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<<arr[i]<<"  ";
//     }
//     cout<<"]";

// }

// Time complexity is O(N) + O(N/2) --> O(N) .
// Space complexity is O(N) , twice of n/2 space for narr and parr .



// Optimal Approach

// int main()
// {
//     int arr[] = {1,2,3,-5,-7,-8};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     // define array for sorting the ans separately .
//     vector<int> ans(n,0) ;
//     // positive elements start from 0 and negative elements start from 1 .
//     int posIndex = 0 , negIndex = 1 ;

//     for(int i = 0 ; i < n ; i++)
//     {   
//         // Fill negative elements in odd indices amd increase the counter (negIndex) by 2 .
//         if(arr[i] < 0)
//         {
//             ans[negIndex] = arr[i] ;
//             negIndex += 2 ;
//         }    
//         // Fill positive elements in even indices amd increase the counter (posIndex) by 2 .

//         else
//         {
//             ans[posIndex] = arr[i] ;
//             posIndex += 2 ;
//         }       
              
//     }

//     // printing the desired sequence
//     cout<<"["; 
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<<ans[i]<<"  ";
//     }
//     cout<<"]";

// }

// Time Complexity is O(N)
// Space Complexity is O(N)



// Variety 2 where number of positive and negative elements are not equal so place the leftover elements at the end in their original sequence , due to this 
// can't use the optimal approach here so fall back to the brute solution .

int main()
{
    int arr[] = {1,2,3,-5,-7,-8,-1,-6,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> pos , neg;
    // segregate the array into positives and negatives 
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > 0)      pos.push_back(arr[i]) ;

        else      neg.push_back(arr[i]) ;

    }

    if(pos.size() > neg.size())
    {
        for(int i = 0 ; i < neg.size() ; i++)
        {
            arr[2*i] = pos[i] ;
            arr[2*i + 1 ] = neg[i] ;
        }

        int limit = 2 * neg.size() ;
        for(int i = neg.size() ; i < pos.size() ; i++)
        {
            arr[limit] = pos[i] ;
            limit++ ; 
        }
    }

    else
    {
        for(int i = 0 ; i < pos.size() ; i++)
        {
            arr[2*i] = pos[i] ;
            arr[2*i + 1 ] = neg[i] ;
        }

        int limit = 2 * pos.size() ;
        for(int i = pos.size() ; i < neg.size() ; i++)
        {
            arr[limit] = neg[i] ;
            limit++ ; 
        }
    }

    // printing the desired sequence
    cout<<"["; 
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<"  ";     
    }
    cout<<"]";

    return 0;
}

// Time complexity is (2*N) , where N is for traversing the array for segreagating and the other N is used in adding the pos and neg part in the end .
// Space complexity is O(N) .