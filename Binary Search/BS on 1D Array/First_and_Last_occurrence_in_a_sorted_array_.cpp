#include<bits/stdc++.h>
using namespace std;

// Naive solution

void solve(int n, int key, vector < int > & v) 
{
    int first = -1 , last = -1 ;

    for (int i = 0 ; i < n ; i++) 
    {
        if (v[i] == key) 
        {
            if(first == -1) 
            {
                first = i;
            }
        
            last = i;
        }
    }
    cout << first << " " << last << endl;

}

int main() 
{
    int n = 7;
    int key = 13;
    vector < int > v = {3,4,13,13,13,20,40};
    solve(n, key, v);

    return 0;
}

//Time complexity : O(n)






// optimized Naive solution

// #include<bits/stdc++.h>
// using namespace std;

// void solve(int n, int key, vector<int>& v) {
//     int first = -1, last = -1;
    
//     // Find first occurrence
//     for(int i = 0; i < n; i++) {
//         if(v[i] == key) {
//             first = i;
//             break;  // Break once we find the first occurrence
//         }
//     }
    
//     // Find last occurrence
//     for(int i = n-1; i >= 0; i--) {
//         if(v[i] == key) {
//             last = i;
//             break;  // Break once we find the last occurrence
//         }
//     }
    
//     cout << first << " " << last << endl;
// }

// int main() {
//     int n = 7;
//     int key = 13;
//     vector<int> v = {3,4,13,13,13,20,40};
//     solve(n, key, v);
//     return 0;
// }

// // time complexity : O(n)





// Using lower bound and upper bound

// int lowerBound(vector<int> &arr, int n, int x) {
//     int low = 0, high = n - 1;
//     int ans = n;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         // maybe an answer
//         if (arr[mid] >= x) {
//             ans = mid;
//             // look for smaller index on the left
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1; // look on the right
//         }
//     }
//     return ans;
// }

// int upperBound(vector<int> &arr, int n, int x) {
//     int low = 0, high = n - 1;
//     int ans = n;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         // maybe an answer
//         if (arr[mid] > x) { // strictly greater than x
//             ans = mid;
//             // look for smaller index on the left
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1; // look on the right
//         }
//     }
//     return ans;
// }

// pair<int, int> solve(vector<int> &v, int n, int key) {
//     int first = lowerBound(v, n, key);
//     int last = upperBound(v, n, key) - 1;
//     if (first == n || v[first] != key) {
//         first = -1;
//         last = -1;
//     }
//     return {first, last};
// }

// int main() 
// {
//     int n = 7;
//     int key = 13;
//     vector<int> v = {3, 4, 13, 13, 13, 20, 40};
//     pair<int, int> p = solve(v, n, key);
//     cout << p.first << " " << p.second << endl;
//     return 0;
// }

// time complexity is O(2logn) = O(logn)





// Binary Search solution  

// int firstOccurence(int n, int key, vector<int>& v) {
//     int start = 0;
//     int end = n - 1;
//     int first = -1;
    
//     while (start <= end) {
//         int mid = start + (end - start) / 2;
//         if (v[mid] == key) {
//             first = mid;
//             end = mid - 1;  // Continue searching in left half
//         }
//         else if (key > v[mid]) {  // Changed condition
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//     }
//     return first;
// }

// int lastOccurence(int n, int key, vector<int>& v) {
//     int start = 0;
//     int end = n - 1;
//     int last = -1;
    
//     while (start <= end) {
//         int mid = start + (end - start) / 2;
//         if (v[mid] == key) {
//             last = mid;
//             start = mid + 1;  // Continue searching in right half
//         }
//         else if (key > v[mid]) {  // Changed condition
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//     }
//     return last;
// }

// pair<int, int> solve(int n, int key, vector<int>& v) {
//     int first = firstOccurence(n, key, v);
//     if(first == -1) 
//     {
//         return {-1, -1};
//     }
//     int last = lastOccurence(n, key, v);
//     return {first, last};
// }

// int main() {
//     int n = 7;
//     int key = 13;
//     vector<int> v = {3,4,13,13,13,20,40};
    
//     pair<int, int> p = solve(n, key, v);
//     cout << p.first << " " << p.second << endl;
    
//     return 0;
// }

// time complexity : O(2*logn) = O(logn)
