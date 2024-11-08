// Enter value of n: 5
// E 
// E D 
// E D C 
// E D C B 
// E D C B A

#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {

    // Upper and lower triangles combined in one loop
    for (int i = 0; i < n; i++) 
    {
        // Print stars
        int x = 65 + n - 1 ;
        for (int j = 0; j <= i; j++) {
            cout <<(char)(x--)<<" ";
            //x--;
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