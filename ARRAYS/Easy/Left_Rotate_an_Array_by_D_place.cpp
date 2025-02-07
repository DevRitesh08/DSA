#include<bits/stdc++.h>
using namespace std;

// brute force approach is to rotate the array one by one , this will take O(n + d) time complexity and the space complexity is O(d)

// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int d ;
//     cout<<"enter the D : ";
//     cin>>d;
//     d = d % n ;
//     int temp[d];
//     // insertion of elements that are to be rotated in the temp array , its time complexity is O(d)
//     for(int i = 0 ; i < d ; i++)
//     {
//         temp[i] = arr[i] ; 
//     }
//     // now shifting the elements of the array to the left , its time complexity is O(n-d)
//     for(int i = d ; i < n ; i++)
//     {
//         arr[i-d] = arr[i];
//     }
//     // now inserting the elements of the temp array to the last of the array , its time complexity is O(d)
//     for(int i = n-d ; i<n ; i++)
//     {
//         arr[i] = temp[i-(n-d)];
//     }

//     // printing the array , not part of the algorithm
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }

// }



// optimized approach ( use the reversal algorithm )
// this will take O(2n) --> O(n) time complexity and the space complexity is O(1)
// time complexity is increased but the space complexity is decreased in comparison to the brute force approach

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d ;
    cout<<"enter the D : ";
    cin>>d;
    d = d % n ;
    // reversing the first d elements , its time complexity is O(d)
    reverse(arr,arr+d);
    // reversing the last n-d elements , its time complexity is O(n-d)
    reverse(arr+d,arr+n);
    // reversing the whole array , its time complexity is O(n)
    reverse(arr,arr+n);
}

// manual reverse function , not part of the algorithm , just for the understanding of the algorithm

// void(reverse(int arr[],int start,int end))
// {
//     while(start < end)
//     {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }

// for revision , do right rotate by d places .