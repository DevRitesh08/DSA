#include<iostream>
using namespace std;


// Better solution

// int main()
// {
//     int arr[]= {8,7,5,2,9,6,3,9,1};
//     int n = 9 ;
//     int smallest = arr[0];
//     int Ssmallest = 100000;      // assuming that all the array elements are less than  100000 .
    
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(arr[i] < smallest)
//             smallest = arr[i];
//     }

//     for(int i = 0 ; i < n ; i++)
//     {
//         if(arr[i] < Ssmallest && arr[i] != smallest)
//             Ssmallest = arr[i];
//     }

//     if(Ssmallest ==  100000)
//         cout<<"Second smallest element does not exists ";
//     else
//     cout<<"The second smallest element of the array is : "<<Ssmallest;
// }

// Optimal solution

int main()
{
    int arr[]= {9,6,7,8,1,3};
    int n = 6 ;
    int smallest = arr[0];
    int Ssmallest = 100000;      // assuming that all the array elements are positive .
    
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] < smallest)
        {
            Ssmallest = smallest ;
            smallest = arr[i];
        }

        else if(arr[i] > smallest && arr[i] < Ssmallest)
        {
            Ssmallest = arr[i];  // Update second smallest if it's greater than smallest
        }
    }

    if(Ssmallest == 100000)
        cout<<"Second largest element does not exists ";
    else
    cout<<"The second largest element of the array is : "<<Ssmallest;
}