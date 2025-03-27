// Given an N×M matrix ‘mat’ where each row is sorted in non-decreasing order and the first element of each row is greater than the last element of the previous row, determine if a given integer ‘target’ exists in ‘mat’.

#include<bits/stdc++.h>
using namespace std;


// Brute Force Approach


bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// Time complaxity is O(N*M) ,  where N = given row number, M = given column number.





// Better Approach (using binary search)


// bool binarySearch(vector<int>& nums, int target) 
// {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }


// bool searchMatrix(vector<vector<int>>& matrix, int target) 
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for (int i = 0; i < n; i++) 
//     {
//         if (matrix[i][0] <= target && target <= matrix[i][m - 1]) 
//         {
//             return binarySearch(matrix[i], target);
//         }
//     }
//     return false;
// }

// Time Complexity: O(N + logM), where N = given row number, M = given column number.
// Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).





// Optimal approach (flattening 2d matrix)

// bool searchMatrix(vector<vector<int>>& matrix, int target) 
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     //apply binary search:
//     int low = 0, high = n * m - 1;
//     while (low <= high) 
//     {
//         int mid = (low + high) / 2;
//         int row = mid / m, col = mid % m;
//         if (matrix[row][col] == target) return true;
//         else if (matrix[row][col] < target) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }

// Time complexity is O(log(M*N)) .
// Reason: We are applying binary search on the imaginary 1D array of size NxM.



int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}