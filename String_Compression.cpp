#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * This class implements two methods to solve the "String Compression" problem (LeetCode #443).
    * Given an array of characters, both methods compress it in-place such that
    * consecutive duplicate characters are replaced by a single instance followed by the count.
    *
    * Example:
    * Input:  ['a','a','b','b','c','c','c']
    * Output: ['a','2','b','2','c','3'], returns 6
    *
    * Methods:
    * 1. BruteForce(vector<char>& chars):
    *    - Builds a new compressed string using extra space.
    *    - Simpler but not optimal (uses O(n) extra space).
    *
    * 2. OptimalApproach(vector<char>& chars):
    *    - Performs compression in-place using two pointers.
    *    - Achieves O(n) time and O(1) extra space.
    *
    * Time Complexity: O(n)
    * Space Complexity:
    *   - BruteForce: O(n)
    *   - OptimalApproach: O(1)
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

    int OptimalApproach(vector<char>& chars) {
        int n = chars.size();
        int idx = 0; // keeps track where to put next character

        for (int i=0; i<n; ) {
            int count = 0;
            char ch = chars[i];

            // count character
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // add chracter
            chars[idx++] = ch;

            // if count is greater than 1
            if (count > 1) {
                string cnt = to_string(count);

                for (char s: cnt) {
                    chars[idx++] = s;
                }
            }
        }

        return idx;
    }
};

// main function
int main() {
    Solution sol;
    vector<char> ch = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'};
    int res = sol.OptimalApproach(ch);
    cout << res;
    
    return 0;
}