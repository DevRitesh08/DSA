#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string dominoes;
    cout << "Enter the dominoes string: ";
    cin >> dominoes;

    int n = dominoes.length();                      // 1. Length of the input string
    string result = dominoes;                       // 2. Make a copy of the input string to modify later
    vector<int> forces(n, 0);                       // 3. Create a forces array of size n, initialized to 0

    // ----------- PASS 1: LEFT TO RIGHT ------------
    int force = 0;                                  // 4. Start with no force
    for (int i = 0; i < n; i++) {
        if (dominoes[i] == 'R')                     // 5. If current is 'R', set full force
            force = n;
        else if (dominoes[i] == 'L')                // 6. If current is 'L', reset force to 0 (left blocks right)
            force = 0;
        else                                        // 7. Otherwise reduce force by 1 (as it spreads)
            force = max(force - 1, 0);
        forces[i] += force;                         // 8. Store the current right force at index i
    }

    // ----------- PASS 2: RIGHT TO LEFT ------------
    force = 0;                                      // 9. Reset force for leftward simulation
    for (int i = n - 1; i >= 0; i--) {
        if (dominoes[i] == 'L')                     // 10. If current is 'L', apply full leftward force
            force = n;
        else if (dominoes[i] == 'R')                // 11. If current is 'R', reset force (right blocks left)
            force = 0;
        else                                        // 12. Otherwise reduce force by 1
            force = max(force - 1, 0);
        forces[i] -= force;                         // 13. Subtract left force from current total force
    }

    // ----------- BUILD FINAL STRING --------------
    for (int i = 0; i < n; i++) {
        if (forces[i] > 0)                          // 14. Net force is rightward → push to 'R'
            result[i] = 'R';
        else if (forces[i] < 0)                     // 15. Net force is leftward → push to 'L'
            result[i] = 'L';
        else                                        // 16. Balanced → stay as '.'
            result[i] = '.';
    }

    cout << "Final dominoes state: " << result << endl;
    return 0;
}
