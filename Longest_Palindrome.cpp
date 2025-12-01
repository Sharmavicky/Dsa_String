#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Finds the longest palindromic substring in a given string using two approaches.
    *
    * The class implements:
    *
    * 1. **BruteForce() – O(n³)**
    *      - Iterates over all possible substrings of the input string.
    *      - Uses the helper function `isPalindrome()` to check if a substring is a palindrome.
    *      - Keeps track of the starting index and length of the longest palindrome found.
    *      - Returns the substring itself.
    *
    * 2. **ExpandAroundCenter() – O(n²)**
    *      - Treats each character (and each pair of consecutive characters) as potential centers of a palindrome.
    *      - Expands outward while the characters on both sides match.
    *      - Updates the start index and length of the longest palindrome dynamically.
    *      - Returns the longest palindromic substring.
    *
    * **Helper Function:**
    * - `isPalindrome(s, left, right)` checks if the substring from index `left` to `right` is a palindrome in O(n) time.
    *
    * These approaches illustrate the transition from a naive cubic solution to a more optimal quadratic solution
    * and are commonly used in string processing, dynamic programming, and competitive programming.
*/

class Solution {
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

public:
    string BruteForce(string s) {
        int n = s.length(), maxLength = 0, startIdx = 0;

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                if (isPalindrome(s, i, j)) {
                    maxLength = max(maxLength, j - i + 1);
                    startIdx = i;
                }
            }
        }

        return s.substr(startIdx, maxLength);
    }

    string ExpandAroundCenter(string s) {
        int n = s.length(), maxLength = 0;
        int start = 0, end = 0;

        for (int center = 0; center < n; center++) {
            // Odd length palindromes
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }

            // Even length palindromes
            left = center, right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLength);
    }
};

// main function
int main() {
    Solution sol;
    string s = "babad";
    cout << "Brute Force: " << sol.BruteForce(s) << endl;
    cout << "Expand Around Center: " << sol.ExpandAroundCenter(s) << endl;
    return 0;
}