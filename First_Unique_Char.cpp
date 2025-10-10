#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * This class provides a solution to the problem "First Unique Character in a String" (LeetCode #387).
    * Given a string `s` consisting of lowercase English letters, it finds the index of the first character
    * that does not repeat anywhere in the string. If no such character exists, it returns -1.
    *
    * Method:
    * 1. firstUniqChar(string s):
    *    - Uses a two-pass approach:
    *      a) First pass: counts the frequency of each character using a fixed-size array of length 26.
    *      b) Second pass: finds the first character with frequency equal to 1.
    *    - This approach ensures linear time complexity and constant extra space.
    *
    * Time Complexity: O(n), where n is the length of the string `s`.
    * Space Complexity: O(1), only a fixed-size frequency array of 26 integers is used.
    *
    * Example:
    * Input:  "loveleetcode"
    * Output: 2  // 'v' is the first non-repeating character
*/

class Solution {
    public:
    int TwoPointerApproach(string s) {
        vector<int> freqMap(26, 0); // index  represent alpahbet

        // store count of every character
        for (char c: s) {
            freqMap[c - 'a']++;
        }

        // now chk which character frequency is 1 and comest first
        for (int i = 0; i <  freqMap.size(); i++) {
            if (freqMap[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }   
};

// main function

int main() {
    string s = "leetcode";
    int res = Solution().TwoPointerApproach(s);
    cout << res;

    return 0;
}