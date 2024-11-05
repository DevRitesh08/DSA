// Enter value of n: 5
// E 
// D E 
// C D E 
// B C D E 
// A B C D E 

#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{

    int x = 65 + n - 1 ;// **LOGIC** 
    
    for (int i = 0; i < n; i++) 
    {
   
        for (int j = 0; j <= i; j++) 
        {
            cout <<(char)(x - i + j)<<" "; // **LOGIC**

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