#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {0, 9, 6, 4},
                     {1, 8, 3, 8},
                     {1, 7, 9, 2}};
    
    int rowSize = sizeof(arr) / sizeof(arr[0]);          // Calculate number of rows
    int colSize = sizeof(arr[0]) / sizeof(arr[0][0]);    // Calculate number of columns

    int ans[rowSize][colSize] = {0};

    // ALGO : Rotate 90 degrees clockwise
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            ans[j][(rowSize - 1) - i] = arr[i][j];
        }
    }

    // Printing the rotated matrix
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0 ;
}

// TIME COMPLEXITY IS O(N^2) .
// SPACE COMPLEXITY IS ALSO O(N^2) , as we are using the ans 2D matrix of size N*N .




// OPTIMAL APPROACH

// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 3, 4},
//                                   {0, 9, 6, 4},
//                                   {1, 8, 3, 8},
//                                   {1, 7, 9, 2}};
//     int n = matrix.size();

//     // Step 1: Transpose the matrix
//     for (int i = 0; i < n; i++)  // Loop over each row
//     {
//         // Loop over columns starting from i+1 to avoid redundant swaps and avoid swapping diagonal elements
//         for (int j = i + 1; j < n; j++)  
//         {
//             swap(matrix[i][j], matrix[j][i]);  // Swap elements across the diagonal
//         }
//     }

//     // Step 2: Reverse each row
//     for (int i = 0; i < n; i++) 
//     {
//         reverse(matrix[i].begin(), matrix[i].end());  // Reverse the elements of row i , tc is O(N)
//     }

//     // Printing the rotated matrix
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < n; j++) 
//         {
//             cout << matrix[i][j] << " ";  
//         }
//         cout << endl;  
//     }

//     return 0;
// }

// Time Complexity: O(N*N) + O(N*N) , One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
// Space Complexity: O(1).