#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Provides two methods to find the length of the longest substring 
    *        without repeating characters in a given string.
    *
    * The class implements:
    *
    * 1. **BruteForce() – O(n²)**
    *      - Iterates over all possible starting indices.
    *      - Uses a set to track characters within the current substring.
    *      - Expands the substring until a repeated character is found.
    *      - Updates the maximum length after every expansion.
    *
    * 2. **SlidingWindow() – O(n)**
    *      - Uses the sliding window technique with two pointers (left & right).
    *      - Maintains an unordered_set to store characters in the current window.
    *      - If a duplicate is encountered, the window shrinks from the left until 
    *        the duplicate is removed.
    *      - Continuously updates the maximum substring length during expansion.
    *
    * These two approaches highlight the transition from a naive quadratic solution
    * to an optimal linear-time sliding window pattern, which is commonly applied in 
    * string processing and real-time streaming problems.
*/


class Solution {
    public:
    int BruteForce(string s) {
        int n = s.length();
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            set<char> charSet;
            for (int j = i; j < n; j++) {
                if (charSet.find(s[j]) != charSet.end()) {
                    break;
                }
                charSet.insert(s[j]);
                maxLength = max(maxLength, j - i + 1);
            }
        }
        return maxLength;
    }

    int SlidingWindow(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;

        int left = 0, right = 0;

        while (right < n) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};

// main function 
int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << "Brute Force: " << sol.BruteForce(s) << endl;
    cout << "Sliding Window: " << sol.SlidingWindow(s) << endl;
    return 0;
}