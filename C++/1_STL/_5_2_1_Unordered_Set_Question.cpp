/*
given N strings and Q queries . in each query you are given a sting print yes if string is present else print no .

N <= 10^6
|S| <= 100
Q <= 10^6
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> s;
    int n ;
    cout<<"enter number of strings to enter : ";
    cin>>n;
    while(n--)
    {
        string x;
        cin>>x;
        s.insert(x);
    }

    int q;
    cout<<"enter number of queries : ";
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;

        if(s.find(str) == s.end() )
        {
            cout<<"No \n";
        }
        else
        {
            cout<<"Yes \n";
        }

    }

}

//input
/*
enter number of strings to enter : 8
abc def abc ghj jkl ghj ghj abc
enter number of queries : 3
abc ghj abcdf
*/

//output
Yes 
Yes 
No 