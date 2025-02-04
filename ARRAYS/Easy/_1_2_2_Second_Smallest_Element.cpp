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
    int arr[]= {1,2,3,4,5,9,6,3,10};
    int n = 9 ;
    int smallest = arr[0];
    int Ssmallest = 100000;      // assuming that all the array elements are positive .
    
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] < smallest)
        {
            Ssmallest = smallest ;
            smallest = arr[i];
        }
    }

    if(Ssmallest == 100000)
        cout<<"Second largest element does not exists ";
    else
    cout<<"The second largest element of the array is : "<<Ssmallest;
}