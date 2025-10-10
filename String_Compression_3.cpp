#include <iostream>
#include <string>
using namespace std;

/*
    * Compresses the given string by replacing consecutive identical characters
    * with the character followed by its count (1–9).
    * If a group exceeds 9, it is split into multiple parts.
    *
    * Example:
    * Input:  "aaaaaaaaaaaaaabb"
    * Output: "a9a5b2"
    *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
*/

class Solution {
    public:
    string compressedString(string word) {
        int n = word.length();
        string comp = ""; // store the newly formed compressed string

        for (int i=0; i<n; ) { 
            char ch = word[i];
            int count = 0;

            // check for similar character and increment count
            while (i < n && word[i] == ch && count < 9) {
                count++;
                i++;
            }

            // first add count and than character
            comp += count + '0';
            comp += ch;
        }

        // return new compressed string
        return comp;
    }
};

// main function
int main() {
    string word = "aaaaaaaaaaaaabbbccc";
    string res = Solution().compressedString(word);

    for (char ch: res) {
        cout << ch << " ";
    }

    return 0;
}