#include<iostream>
using namespace std;


// Better solution

// int main()
// {
//     int arr[]= {1,2,3,4,5,9,6,3,10};
//     int n = 9 ;
//     int largest = arr[0];
//     int Slargest = -1;      // assuming that all the array elements are positive .
    
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(arr[i] > largest)
//             largest = arr[i];
//     }

//     for(int i = 0 ; i < n ; i++)
//     {
//         if(arr[i] > Slargest && arr[i] != largest)
//             Slargest = arr[i];
//     }

//     if(Slargest == -1)
//         cout<<"Second largest element does not exists ";
//     else
//     cout<<"The second largest element of the array is : "<<Slargest;
// }

// Optimal solution

int main()
{
    int arr[]= {1,2,3,4,5,9,6,3,10};
    int n = 9 ;
    int largest = arr[0];
    int Slargest = -1;      // assuming that all the array elements are positive .
    
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > largest)
        {
            Slargest = largest ;
            largest = arr[i];
        }
        
        else if(arr[i] < largest && arr[i] > Slargest)
            Slargest = arr[i];
    }

    if(Slargest == -1)
        cout<<"Second largest element does not exists ";
    else
    cout<<"The second largest element of the array is : "<<Slargest;
}