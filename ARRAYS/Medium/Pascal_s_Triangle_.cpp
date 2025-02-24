#include<bits/stdc++.h>
using namespace std ;


// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.



// Variation 1

// int ncr(int n , int r)
// {
//     long long  res = 1 ;

//     for(int i = 0 ; i < r ;i++)
//     {
//         // res = res*(n-i) ;
//         // res = res/(i+1) ;
//         // // or directly
//         res = res*(n-i)/(i+1) ;
//     }
//     return res;
// }

// int pascalTriangle(int r , int c)
// {
//     return ncr(r-1 , c-1) ;
// }

// int main()
// {
//     int r = 5 , c = 3 ;
//     int element = pascalTriangle(r , c) ;
//     cout<<"the element at position ("<<r<<","<<c<<") is "<<element<<endl;
//     return 0 ;
// }

// Time Complexity: O(c), where c = given column number.
// Reason: We are running a loop for r times, where r is c-1.
// Space Complexity: O(1) as we are not using any extra space.



// Variation 2


// naive approach

// In this approach, for every column from 1 to n, we will calculate the element (n, c)(where n is the given row number and c is the column number that will vary from 1 to n) using the previous method. Thus, we will print the row.  

// int ncr(int n , int r)
// {
//     long long res = 1;

//     for(int i = 0 ; i < r ; i++)
//     {
//         res = res*(n-i)/(i+1) ;
//     }
//     return res;
// }

// int pascalTriangle(int n)
// {
   
    
//     for(int c = 1 ; c <= n ; c++)
//     {
//         cout<<ncr(n-1 , c-1)<<"  ";
//     }

// }

// Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
// Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.
// Space Complexity: O(1) as we are not using any extra space.




// Optimized approach

// void pascalTriangle(int n) {
//     long long ans = 1;
//     cout << ans << " "; // printing 1st element of every row as 1 .

//     //Printing the rest of the part:
//     for (int i = 1; i < n; i++) {
//         ans = ans * (n - i);
//         ans = ans / i;
//         cout << ans << " ";
//     }
//     cout << endl;
// }

// Time Complexity: O(n), where n is the given row number.
// Reason: We are running a loop for n times.
// Space Complexity: O(1) as we are not using any extra space.



// int main()
// {
//     int n = 5 ;
//     pascalTriangle(n) ;
//     return 0 ;
// }



// Variation 3


// naive approach

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
    return 0;
}
