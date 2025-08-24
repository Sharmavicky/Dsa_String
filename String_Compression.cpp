#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
    * Problem: Given a character array chars, compress it using the following algorithm:

    * - Begin with an empty string s. For each group of consecutive repeating characters in chars:
    *   - If the group's length is 1, append the character to s.
    *   - If the group's length is greater than 1, append the character followed by the group's length to s.

    * - The compressed string should replace the original characters in chars.
    * - Return the new length of chars after compression.
    
    * Time Complexity: O(n), where n is the length of the input vector chars.
    * Space Complexity: O(n), for storing the compressed string.

*/
class Solution {
    public:
    int BruteForce(vector<char>& chars) {
        int count = 0, n = chars.size();
        string compressedStr = "";

        for (int i=0; i<n;) {
            // Reset count for each new character
            count = 1;

            // Append character to the result
            compressedStr += chars[i];

            // count consecutive characters
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                count++;
                j++;
            }

            // If count is greater than 1, append the count as well
            if (count > 1) {
                compressedStr += to_string(count);
            }

            // Move i to the next new character
            i = j;
            j = i + 1; // Reset j to the next character
        }

        // clear the original vector and fill it with compressed characters
        chars.clear();

        for (char c: compressedStr) {
            chars.push_back(c);
        }

        // return the new length of the compressed chars
        return chars.size();
    }
};