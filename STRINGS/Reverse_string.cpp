#include<bits/stdc++.h>
using namespace std;

// 1. for the character array ==>

// int main()
// {
//     char st[] = {'a','b','c','d','e'};
//     int n = sizeof(st) / sizeof(st[0]);
//     int start = 0, end = n - 1;
//     while(start < end)
//     {
//         swap(st[start], st[end]);
//         start++;
//         end--;
//     }
//     cout << "The reversed string is: ";
//     for(int i = 0; i < n; i++)
//     {
//         cout << st[i] << " ";
//     }

//     return 0;
// }





// for string ==>

int main()
{
    string st = "hello everyone this is ritesh swami";
    reverse(st.begin(),st.end());   // iterators
    int  n = st.length();
    for(int i = 0; i < n; i++)
    {
        cout << st[i] << " ";
    }
    // or
    // cout<<st ;

    return 0;
}