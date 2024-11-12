#include <bits/stdc++.h>
using namespace std;

int main() 
{

    string s;
    cout<<"Enter the string : ";
    cin >> s;
    
    //precompute:
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) 
    {
        mp[s[i]]++;
    }

    // // iterate over the map: (To print the map )
    // for(auto it : mp)
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }
    

    int q;
    cout<<"Enter number of queries : ";
    cin >> q;
    cout<<"Enter queries : ";
    while (q--) {
        char ch;
        cin >> ch;
        // fetch:
        cout << mp[ch] << endl;
    }
    return 0;
}