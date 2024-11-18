/*
Given N strings , print unique strings in lexiographical order
N <= 10^5
|S| <= 100000
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    set <string> s ;
    int n;
    cout<<"enter number of strings to enter : ";
    cin>>n;

    while(n--)
    {
        string str;
        cout<<"enter string : ";
        cin>>str ;
        s.insert(str);
    }

        for(auto value : s)
            cout<<value<<" ";
}

// input
/*
enter number of strings to enter : 8
enter string : abc
enter string : def
enter string : abc
enter string : ghj
enter string : jkl
enter string : ghj
enter string : ghj
enter string : abc
*/

//output
/*
abc def ghj jkl 
*/