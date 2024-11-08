#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s ;
    cout<<"Enter string : ";
    cin >> s ; 
   
    //precompute:
    int hash[26] = {0};

    for (int i = 0; i < 26 ; i++) 
    {
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cout<<"Enter number of queries to search : ";
    cin >> q;
    cout<<"enter queries : ";
    while (q--) 
    {
        char c ;
        cin >> c;
        // fetching:
        cout << hash[ c - 'a'] << endl;
    }
    return 0;
}