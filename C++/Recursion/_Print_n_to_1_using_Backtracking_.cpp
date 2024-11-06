// here in back_tracking we can't use decrement operators -- , - etc in case of printing n to 1 numbers .

#include <bits/stdc++.h>
using namespace std;

void f(int i, int num) {
    if (i > num)
        return;

    f(i + 1, num); // Recursive call first (go deeper)
    cout << i << endl; // Print the number while backtracking
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    f(1, num); // Start the recursion from 1
    return 0;
}
