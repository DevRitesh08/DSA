#include<bits/stdc++.h>
using namespace std;

// brute force approach 
// It's time complexity is O(2n) --> O(n) and spacecomplexity is O(x)  , where x is the number of non-zero elements , in the worst case it will be O(n) when there is no zeroes present in the array .

// int main()
// {
//     int arr[] = {1,0,2,0,0,0,3,0,4,0,5,0,0,6,0,7,0,8,0};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     vector<int> temp;
//     // taking all the non zero elements in the temp vector , its time complexity is O( n )
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(arr[i] != 0)
//         {
//             temp.push_back(arr[i]);
//         }
//     }
//     // inserting back the non zero elements in the array , its time complexity is O( x )
//     for(int i = 0 ; i < temp.size() ; i++)
//     {
//         arr[i] = temp[i];
//     }
//     //now inserting the zeroes in the array , its time complexity is O(n - x)
//     for(int i = temp.size() ; i < n ; i++)
//     {
//         arr[i] = 0 ;
//     }

//     // printing the array , not part of algo .
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<<arr[i]<<" ";
//     } 
// }



// Optimal approach ( 2 - pointer )
// Time complexity is O(n) and Space complexity is O(1) .

int main()
{
    int arr[] = {1,0,2,0,0,0,3,0,4,0,5,0,0,6,0,7,0,8,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j = -1 ; // can't take 0 as we don't know whether arr[0] is a zero element or not . 
    // finding the first zero element , its time complexity is O(x)  , where x is the number of iterations taken by the loop to find the first zero , in the worst case it will be O(n) when there is no zeroes present in the array .
    for(int i = 0 ; i < n ; i++)
    {
        if (arr[i] == 0)
        {
            j = i ;
            break;
        }

    }

    // now , swapping the zeroes with the non-zero elements coming later in the iterations of the loop
    // it's time complexity is O(n - x) 
    for(int i = j+1 ; i < n ; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i],arr[j]); // swapping the non zero element with the zero element , its time complexity is O(1)
            j++;
        }
    }


}