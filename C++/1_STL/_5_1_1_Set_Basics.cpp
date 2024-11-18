// It is just like the map but here values are not stored , it just a collection of keys which are stored in a sorted order and obviously its elements(keys) are unique .
// also be defined as it is a collection of unique numbers or elements .
#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string> st;
    st.insert("abc");// TIME COMPLEXITY of single insertion operation is here also O(logN) .
    st.insert("sff");
    st.insert("zvc");

    auto it = st.find("abc");

    // printing of set


    //method 1

    for(string value : st)
    {
        cout<< value <<endl;
    }

    // //method 2
    // for(auto it = st.begin() ; it != st.end() ; it++)
    // {
    //     cout<<(*it)<<endl;
    // }


    auto it2 = st.find("abc"); // TIME COMPLEXITY IS O(logN) .
    // check
    if(it2 != st.end() )
    {
        st.erase(it2);
    }

    cout<<"after using erase : "<<endl;
    for(string value : st)
    {
        cout<< value <<endl;
    }

    // other way to erase
    st.erase("zvc");
    cout<<"after using erase : "<<endl;
    for(string value : st)
    {
        cout<< value <<endl;
    }

}