// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (Linear Search) :

int floorSqrt(int num)
{
    int ans = 1;

    for(int i = 1 ; i <= num ; i++)
    {
        if (i*i <= num)   ans = i;

        else    break;

    }
    return ans;
}

// Time Complexity: O(√N)
// Reason: The loop runs until i*i > num, which means it stops around i ≈ √N





// Optimal Approach 1 (Using in-built sqrt() function):

// int floorSqrt(int n) 
// {
//     int ans = sqrt(n); // floor value is taken as ans is an integer.
//     return ans;
// }

// Time Complexity: O(1)
// Reason: The sqrt(n) function in C++ runs in O(1) due to hardware acceleration (FPU), Newton-Raphson (fixed iterations), and optimized assembly instructions (FSQRT), ensuring constant-time execution regardless of n.





// Optimal Approach 2 (Using binary search): 

// int floorSqrt(int n) 
// {
//     int start = 1, end = n;
//     int ans = 1 ;
    
//     while(start <= end)
//     {
//         long long mid = (start + end)/2 ;
//         // long long mid = start + (end - start)/2; // To avoid overflow
//         long long val = mid*mid;

//         if (val <= (long long)(n)) {
//             //eliminate the left half:
//             ans = mid;
//             start = mid + 1;
//         }
//         else {
//             //eliminate the right half:
//             end = mid - 1;
//         }
//     }
//     return ans; // or return end ; (both will give the same answer) 
// }

// Time Complexity: O(logN), N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.




int main()
{
    cout<<"Enter the number : "<<endl;
    int n;
    cin>>n;
    int ans = floorSqrt(n);
    cout<<"The square root of "<<n<<" is : "<<ans<<endl;
    return 0;
}

// for questions related to BS on Answers , you should know the range of the answer and they are generally asked in the form of finding min and max values of the answer , then apply binary search on it  
