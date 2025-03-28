// You have an N×M matrix ‘mat’ where each row and column is sorted in non-decreasing order, but the first element of a row may not exceed the last element of the previous row. Given an integer ‘target’, determine if it exists in ‘mat’.


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (linear search)

bool searchElement(vector<vector<int>>& matrix, int target) 
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

// time complexity  is O(n*m)





// Better Solution ( using binary search)

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

// bool searchElement(vector<vector<int>>& matrix, int target) 
// {
//     int n = matrix.size();

//     for (int i = 0; i < n; i++) 
//     {
//         bool flag =  binarySearch(matrix[i], target);
//         if (flag) return true;
//     }
//     return false;
// }

// Time Complexity: O(N*logM), where N = given row number, M = given column number.
// Reason: We are traversing all rows and it takes O(N) time complexity. And for all rows, we are applying binary search. So, the total time complexity is O(N*logM).





// Optimal Solution

// bool searchElement(vector<vector<int>>& matrix, int target) 
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     int row = 0, col = m - 1;

//     //traverse the matrix from (0, m-1):
//     while (row < n && col >= 0) 
//     {
//         if (matrix[row][col] == target) return true;
//         else if (matrix[row][col] < target) row++;
//         else col--;
//     }
//     return false;
// }

// Time Complexity: O(N+M), where N = given row number, M = given column number.
// Reason: We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0). So, the total distance can be at most (N+M). So, the time complexity is O(N+M).



int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}
