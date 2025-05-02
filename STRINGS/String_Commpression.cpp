#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Function to compress the vector of characters
int compress(vector<char>& chars) 
{
    int n = chars.size();  // Total number of characters in the input
    int idx = 0;           // Index to store the compressed characters

    // Traverse the input characters
    for (int i = 0; i < n; i++) 
    {
        char ch = chars[i];   // Current character
        int count = 0;        // Count occurrences of the current character

        // Count how many times the same character repeats consecutively
        while (i < n && chars[i] == ch) 
        {
            count++;
            i++;
        }

        // Add the character to the compressed list
        chars[idx++] = ch;

        // If the character appears more than once, add its count as string
        if (count > 1) 
        {
            string str = to_string(count);  // Convert count to string
            for (char dig : str) {
                chars[idx++] = dig;        // Add each digit of count separately
            }
        }

        i--; // Step back once because the outer loop will increment i again
    }

    // Resize the vector to the new compressed size
    chars.resize(idx);
    return idx; // Return the length of the compressed array
}

// Time complexity is O(N) , not O(N^2) as both loops are incrementing i , so they are not nested .




int main() 
{
    string input;
    cout << "Enter characters (no space, e.g. aabccc): ";
    cin >> input;

    // Convert input string to vector<char>
    vector<char> chars(input.begin(), input.end());

    // Call compress function
    int newLength = compress(chars);

    // Output result
    cout << "Compressed characters: ";
    for (char c : chars) 
    {
        cout << c;
    }
    cout << "\nLength of compressed array: " << newLength << endl;

    return 0;
}
