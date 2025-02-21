#include<bits/stdc++.h>
using namespace std;
#define N 3

// BRUTE SOLUTION

// Notice the matrix is passed with fixed row size and variable column size. The N is used to define the size of the matrix.
void transpose(int matrix[][N]) 
{

    int temp[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout<<temp[i][j]<<" ";
        }
        
        cout<<endl;
    }      
}

// Time complexity: O(n*m) for traversing
// Space complexity: O(n*m) for new matrix



// Optimal approach

// Intuition:
// From the definition of transpose it is known that transposing of a matrix is interchanging the rows and columns, so to achieve this, we can directly interchange elements without using extra space.


// void transpose(int matrix[][N]) 
// {

//     int temp[N][N];

//     for (int i=0;i<N;i++){
//         for (int j=i+1;j<N;j++){
//                     int temp = matrix[i][j];
//                     matrix[i][j] = matrix[j][i];
//                     matrix[j][i] = temp;
//                 }
//             }

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


int main() 
{
        
    int matrix[3][3]=  { {4,5,6}, {7,8,9}, {10,11,12}};
       
    transpose(matrix) ;  

    return 0 ;
}