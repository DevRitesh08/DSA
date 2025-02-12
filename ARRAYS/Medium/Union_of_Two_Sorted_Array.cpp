#include<bits/stdc++.h>
using namespace std;


// // Brute Force Approach
// // Time complexity is O( n1*logn + n2*logn + (n1 + n2) )
// // space complexity is O(n1 + n2) , it is the size of the set , size of the union array (n1 + n2 ) is not added here because it is not used to solve the problem it is used to return the answer .
// int main()
// {
//     int arr1[] = {1,1,3,4,4,4,5,6,6};
//     int arr2[] = {1,2,3,6,7,7,8,9,9};
//     set <int> s;

//     // inserting the elements of arr1 in set s , It's time complexity is O(n1*logn) where n1 is the size of arr1 and n is the size of set .
//     for(int i = 0 ; i < sizeof(arr1)/sizeof(arr1[0]) ; i++)
//     {
//         s.insert(arr1[i]);
//     }
//     // inserting the elements of arr1 in set s, It's time complexity is O(n2*logn) where n2 is the size of arr2 and n is the size of the set .
//     for(int i = 0 ; i < sizeof(arr2)/sizeof(arr2[0]) ; i++)
//     {
//         s.insert(arr2[i]);
//     }

//     // now inserting the set s into the union array , It's time complexity is O(n1 + n2)
//     int union_arr[s.size()];
//     int i = 0 ;
//     for(auto it : s)
//     {
//         union_arr[i++] = it;
//     }
    
//     //alternate of above 
//     // vector <int> temp;
//     // for(auto it : temp)
//     // {
//     //     temp.push_back(it) ;
//     // }

//     // printing the union array
//     for(int i = 0; i < s.size(); i++) {
//         cout << union_arr[i] << " ";
//     }
//     cout << endl;


// }



// Optimal Approach
// Time complexity is O(n1 + n2) where n1 is the size of arr1 and n2 is the size of arr2
// space complexity is O(n1 + n2) , it is the size of the union array and it is not used to solve the problem it is used to return the answer .

int main()
{
    int arr1[] = {1,1,3,4,4,4,5,6,6};
    int arr2[] = {1,2,3,6,7,7,8,9,9};
    vector <int> union_arr ;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int i = 0; // pointers for arr1 
    int j = 0 ; //pointer for arr2
    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j]) 
        {
            if(union_arr.size() == 0 || union_arr.back() != arr1[i])
            {
                union_arr.push_back(arr1[i]);
            }
            i++ ;

        }
        else
        {
            if(union_arr.size() == 0 || union_arr.back() != arr2[j])
            {
                union_arr.push_back(arr2[j]);
            }
            j++ ;

        }
    }
    while(j < n2)
    {
        if(union_arr.size() == 0 || union_arr.back() != arr2[j])
            {
                union_arr.push_back(arr2[j]);
            }
            j++ ;
    }
    while(i < n1)
    {
        if(union_arr.size() == 0 || union_arr.back() != arr1[i])
        {
            union_arr.push_back(arr1[i]);
        }
        i++ ;

    }

    // printing of union array
    for(int i = 0; i < union_arr.size(); i++) {
        cout << union_arr[i] << " ";
    }

}

