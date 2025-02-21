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
}

// TIME COMPLEXITY IS O(N^2) .
// SPACE COMPLEXITY IS ALSO O(N^2) , as we are using the ans 2D matrix of size N*N .
