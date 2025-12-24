#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Converts a given string into its Zigzag pattern representation
    *        based on the specified number of rows.
    *
    * The algorithm simulates writing characters in a zigzag (downward and
    * diagonal upward) pattern across multiple rows and then reads the
    * pattern row by row to produce the final string.
    *
    * Approach:
    *   - Handle the edge case when numRows is 1 (no zigzag possible).
    *   - Use a vector of strings where each index represents a row.
    *   - Traverse the input string while tracking the current row and
    *     direction of movement (down or up).
    *   - Append each character to its corresponding row.
    *   - Concatenate all rows to obtain the final result.
    *
    * Time Complexity: O(n), where n is the length of the string.
    * Space Complexity: O(n), used to store characters in row-wise fashion.
    *
    * This approach is efficient, easy to understand, and avoids explicitly
    * constructing the zigzag matrix.
*/

class Solution {
    public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1, return the original string
        if (numRows == 1) return s;

        // Create a vector of strings to hold each row
        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        // Traverse the input string and place characters in the appropriate row
        for (char c: s) {
            rows[currRow] += c;

            // Change direction at the first and last rows
            if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final result
        string result;
        for (const string& row: rows) {
            result += row;
        }

        return result;
    }
};

// main function
int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string res = Solution().convert(s, numRows);
    cout << res << endl; // Output: "PAHNAPLSIIGYIR"

    return 0;
}