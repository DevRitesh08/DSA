// Enter value of n: 5
//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *

#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {
    int star = 1;
    int space = n - 1;

    // Upper and lower triangles combined in one loop
    for (int i = 0; i < 2 * n - 1; i++) {
        // Print spaces
        for (int j = 0; j < space; j++) {
            cout << " ";
        }

        // Print stars
        for (int j = 0; j < star; j++) {
            cout << "*";
        }

        // Adjust the number of stars and spaces
        if (i < n - 1) {
            star += 2;
            space--;
        } else {
            star -= 2;
            space++;
        }

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    pattern(n);
    return 0;
}
