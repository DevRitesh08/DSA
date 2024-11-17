/*
Given N strings , print unique strings in lexiographical order with their frequency .
N <= 10^5
|S| <= 100
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m ; // here key is string because we need  unique strings in lexiographical order (sorted ) and value as int because we want frequency of same strings if present .
    int n;
    cout<<"number of strings : ";
    cin>>n;
    for(int i = 0 ; i < n ; i++) 
    {
        string s;
        cin>>s;
        m[s]++; // for frequency
    }

    for(auto pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }

}
//ex -->
// input
/*
number of strings : 8
abc
def
abc
ghj
jkl
ghj
ghj
abc
*/ 
// output
/*
abc 3
def 1
ghj 3
jkl 1
*/