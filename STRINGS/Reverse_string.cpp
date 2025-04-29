#include <bits/stdc++.h>
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




// for string using stack

// int main() 
// {
//     vector<char> s = {'a', 'b', 'c', 'd', 'e'};
//     stack<char> st;
//     int i = 0;
//     while(i < s.size()) {
//         st.push(s[i]);
//         i++;
//     }
//     s.clear();
//     while(!st.empty()) {
//         char ch = st.top();
//         st.pop();
//         s.push_back(ch);
//     }

//     cout << "The reversed string is: ";
//     for(char c : s) {
//         cout << c << " ";
//     }
//     return 0;
// }

// Time complexity is O(2N)
// Space complexity is O(N)




// for string using two-pointer

int main() 
{
    vector<char> s = {'a', 'b', 'c', 'd', 'e'};

    int start = 0;
    int end = s.size()-1;

    while(start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }  

    cout << "The reversed string is: ";
    for(char c : s)
    {
        cout << c << " ";
    }

    return 0;
}
// Time complexity is O(N)
// Space complexity is O(1)

