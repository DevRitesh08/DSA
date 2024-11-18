// It is just like the map but here values are not stored , it just a collection of keys which are stored in a sorted order and obviously its elements(keys) are unique .
// also be defined as it is a collection of unique numbers or elements .
#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string> st;
    st.insert("abc");
    st.insert("sff");
    st.insert("zvc");

    auto it = st.find("abc");

    // for(string &value : st)
    // {
    //     cout<<st<<endl;
    // }
    for(auto it = st.begin() ; it != st.end() ; it++)
    {
        cout<<(*it)<<endl;
    }


}