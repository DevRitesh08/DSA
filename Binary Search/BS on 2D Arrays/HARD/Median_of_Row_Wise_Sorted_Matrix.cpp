// Problem Statement: Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.
// Note: MXN is odd.


#include<bits/stdc++.h>
using namespace std;

// Brute force solution :
// The extremely naive approach is to use a linear array/list to store the elements of the given matrix. Now, we will sort the list and return the middle element.

int median(vector<vector<int>> &matrix, int m, int n) 
{
    vector<int> lst;

    //traverse the matrix and
    //copy the elements to list:
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            lst.push_back(matrix[i][j]);
        }
    }

    //sort the list:
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}

// Time Complexity: O(MXN) + O(MXN(log(MXN))), where M = number of row in the given matrix, N = number of columns in the given matrix
// Reason: At first, we are traversing the matrix to copy the elements. This takes O(MXN) time complexity. Then we are sorting the linear array of size (MXN), that takes O(MXN(log(MXN))) time complexity

// Space Complexity: O(MXN) as we are using a temporary list to store the elements of the matrix.





// Optimal solution (Binary Search) :




int main() {
    vector<vector<int>> matrix = 
    {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}