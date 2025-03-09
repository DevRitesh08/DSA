// Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (Linear Search) :


// Power exponential method:
long long func(int b, int exp) // O(log exp) => O(log n) , as exp is n here.
{
    long long  ans = 1;
    long long base = b;

    while (exp > 0) 
    {
        if (exp % 2) 
        {
            exp--;
            ans = ans * base;
        }
        else 
        {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRoot(int n, int m) 
{
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) 
    {
        long long val = func(i, n); // or use in-built pow() function , ex: pow(i,n) ==> Time Complexity: O(logn)
        if (val == m * 1ll) return i;
        else if (val > m * 1ll) break;
    }
    return -1;
}

// Time Complexity: O(m*logn), where m is the answer and n is the root.
// Reason: Since we are using linear search, we traverse the entire answer space. (if for loop method is used to calculate the power, then the time complexity will be O(m*n) )





// Optimal Approach (Using binary search):


//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) 
{
    long long ans = 1;
    for (int i = 1; i <= n; i++) 
    {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) 
{
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Time Complexity: O(logm * n), where m is the answer and n is the root (time complexity here is less than the brute force approach).
// O(M * log n) and O(log M * n) appear similar, but O(log M * n) is exponentially faster for large M.




int main()
{
    cout<<"enter the value of n (root) and m (number) : ";
    int n , m ;
    cin>>n>>m;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
