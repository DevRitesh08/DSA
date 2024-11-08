#include<bits/stdc++.h>
using namespace std ;

bool PD(int i , string &s)
{
    if( i >= s.length()/2) return true ;// true --> 1
    if( s[i] != s[s.length() - i - 1] ) return false ;// false --> 0

    return PD(i + 1 , s);
}

int main()
{
    string s = "madam";
    cout<<PD(0 , s);
    return 0;
}