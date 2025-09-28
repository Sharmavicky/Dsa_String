#include <iostream>
#include <string>
using namespace std;

/*
    * Class Solution provides an implementation to solve the
    * "Maximum Number of Vowels in a Substring of Given Length" problem (LeetCode 1456).
    *
    * Problem:
    * Given a string s and an integer k, return the maximum number of vowels
    * contained in any substring of length k.
    *
    * Approach (Sliding Window):
    * - Count the number of vowels in the first window of size k.
    * - Then slide the window across the string:
    *     - Add the new character if it's a vowel.
    *     - Remove the outgoing character if it's a vowel.
    *     - Update the maximum vowel count.
    *
    * Time Complexity: O(n), where n = length of string.
    * Space Complexity: O(1), since only a few variables are used.
*/

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int slidingWindowApproach(string s, int k) {
        int vowelCnt = 0, maxVowel = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) vowelCnt++;
        }

        maxVowel = vowelCnt;

        for (int i = k; i < s.length(); i++) {
            // add new character & chk if it is vowel or not
            if (isVowel(s[i])) vowelCnt++;

            // remove previous first character of window or reduce vowelCnt if it's a vowel
            if (isVowel(s[i - k])) vowelCnt--;

            // update maxVowels
            maxVowel = max(maxVowel, vowelCnt);
        }

        return maxVowel;
    }
};

// main function
int main() {
    string s = "abcdeiifc";
    int k = 5;

    int res = Solution().slidingWindowApproach(s, k);
    cout << res;
    return 0;
}