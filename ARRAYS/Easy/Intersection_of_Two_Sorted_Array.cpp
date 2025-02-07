#include<bits/stdc++.h>
using namespace std;

// //Brute Force Approach
// //Time complexity is O(n1*n2) where n1 is the size of arr1 and n2 is the size of arr2 .
// //space complexity is O(n2) , it is the size of the visited array .
// //The visited array is used to keep track of the elements of arr2 which are already visited.

// int main()
// {
//     int arr1[] = {1,1,3,4,4,4,5,6,6};
//     int arr2[] = {1,2,3,6,7,7,8,9,9};
//     vector <int> intersection_arr ;
//     int n1 = sizeof(arr1)/sizeof(arr1[0]);
//     int n2 = sizeof(arr2)/sizeof(arr2[0]);
//     int visited_array[n2] = {0};

//     for(int i = 0 ; i < n1 ; i++)
//     {
//         for(int j = 0 ; j < n2 ; j++)
//         {
//             if(arr1[i] == arr2[j] && visited_array[j] == 0)
//             {
//                 intersection_arr.push_back(arr1[i]);
//                 visited_array[j] = 1;
//                 break;
//             }
//             if(arr1[i] < arr2[j]) //As the array is sorted if the element of arr1 is less than the element of arr2 then we can break the loop as the element of arr1 will not be present in the array arr2
//             {
//                 break;
//             }
//         }
//     }

//     //Printing the intersection array
//     for(int i = 0 ; i < intersection_arr.size() ; i++)
//     {
//         cout<<intersection_arr[i]<<" ";
//     }

// }



//Optimal Approach (Two Pointer Approach)
//Time complexity is O( n1 + n2 ) where n1 is the size of arr1 and n2 is the size of arr2 .
//space complexity is O(1) , as we are not using any extra space. intersection_arr is the output array and it is not considered as extra space.

int main()
{
    int arr1[] = {1,1,3,4,4,4,5,6,6};
    int arr2[] = {1,2,3,6,7,7,8,9,9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector <int> intersection_arr ;
    int i = 0 , j = 0;

    for(i = 0 , j = 0 ; i < n1 && j < n2 ;)
    {
        if(arr1[i] == arr2[j])
        {
            intersection_arr.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    //Printing the intersection array
    for(int i = 0 ; i < intersection_arr.size() ; i++)
    {
        cout<<intersection_arr[i]<<" ";
    }

} 