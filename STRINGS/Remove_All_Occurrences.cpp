#include<bits/stdc++.h>
using namespace std ;

int main() {
    string s = "daabcbaabcbc";  // Example input string
    string part = "abc";        // Substring to remove

        // s.find(part) provides the index of first character of the substring
        // part whose occurrences are to be removed .
        while( s.length() > 0 && s.find(part) < s.length() )
        {
            // s.erase(start , end) , it helps in  removing the substring by 
            // taking its start which is s.find(part) and its end which will be 
            // the length of the substring .
            s.erase( s.find(part) , part.length() ) ;
        }

    cout << "Result: " << s << std::endl;
    return 0;
}


// Time Complexity is O(N^2) .