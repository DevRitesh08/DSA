#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s ;
    cout<<"Enter string : ";
    cin >> s ; 
   
    //precompute:
    int hash[256] = {0};

    for (int i = 0; i < s.size() ; i++) 
    {
        hash[s[i]] ++ ;
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
        cout << hash[ c ] << endl;
    }
    return 0;
}