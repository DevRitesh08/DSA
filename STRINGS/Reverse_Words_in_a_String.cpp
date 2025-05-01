#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) 
{
    string ans = "";
    // Step 1: Reverse the entire string
    reverse(s.begin(), s.end());

    // Step 2: Process each word and reverse it back individually
    for (int i = 0; i < s.length(); i++) 
    {
        string word = "";
        // Extract one word (until space or end of string)
        while (i < s.length() && s[i] != ' ') 
        {
            word += s[i];
            i++;
        }
        // Step 3: Reverse the extracted word
        reverse(word.begin(), word.end());
        // Step 4: If word is not empty, add it to the result
        if (word.length() > 0) 
        {
            ans += " " + word;
        }
    }
    // Step 5: Remove the leading space added at the start
    return ans.substr(1);
}

// Time complexity is O(N) .


int main() 
{
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);  // Read full line with spaces

    string result = reverseWords(input);
    cout << "Reversed words: " << result << endl;

    return 0;
}
