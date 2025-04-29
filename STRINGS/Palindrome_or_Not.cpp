#include <bits/stdc++.h>
using namespace std;

bool isalphanum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (!isalphanum(s[start]))
        {
            start++;
            continue;
        }

        if (!isalphanum(s[end]))
        {
            end--;
            continue;
        }

        if (tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

// Time complexity is O(N) .



int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);  // allows input with spaces

    if (isPalindrome(s))
    {
        cout << "The string is a valid palindrome.\n";
    }
    else
    {
        cout << "The string is NOT a valid palindrome.\n";
    }

    return 0;
}
