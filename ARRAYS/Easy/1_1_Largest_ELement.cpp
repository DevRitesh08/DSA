// Optimal solution

#include<iostream>
using namespace std;
int main()
{
    int arr[]= {1,2,3,4,5,9,6,3,10};
    int n = 9 ;
    int largest = arr[0];

    for(int i=0; i < n ;i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout<<"the largest element of the array is : "<<largest;
    
}