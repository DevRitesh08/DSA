/*
Given N strings and Q queries. in each query you are given a string ,print frequency of that string .
N <= 10^6
|S| <= 100
Q <= 10^6
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> m ; // here key is string because we need  unique strings in lexiographical order (sorted ) and value as int because we want frequency of same strings if present .
    int n;
    cout<<"number of strings : ";
    cin>>n;
    for(int i = 0 ; i < n ; i++) 
    {
        string s;
        cin>>s;
        m[s]++; // for frequency
    }

    int q ;
    cout<<"Enter number of queries :";
    cin>>q ;

   while(q--)
   {
        string s;
        cin>>s;
        cout<<m[s]<<endl;
   }

}
//ex -->
// input
/*
number of strings : 8
abc def abc ghj jkl ghj ghj abc
Enter number of queries :2
abc ghj
*/
// output
/*
3
3
*/