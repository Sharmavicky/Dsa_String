#include <iostream>
#include <string>
using namespace std;

/*
    Problem here is to check if a given string is a palindrome, ignoring non-alphanumeric characters and case.

    Time Complexity: {
        Brute Force Approach: O(n)
        Better Approach: O(n)
    }
    
    Space Complexity: {
        Brute Force Approach: O(n) // for the result string
        Better Approach: O(1) // no extra space used
*/

class Solution {
    public:
    bool BruteForce(string s) { // Tc: O(n), Sc: O(n)
        string result = "";

        for (char c : s) {
            // check if character is alphanumeric
            if (isalnum(c)) {
                c = tolower(c);
                result += c;
            }
        }

        int left = 0, right = result.size()-1;

        while (left < right) {
            if (result[left] != result[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    bool BetterApproach(string s) {
        int left = 0, right = s.size()-1;

        while (left < right) {
            // skip non-alphanumeric characters
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // compare characters in a case-insensitive manner
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};

// main function
int main() {
    string s = "A man, a plan, a canal: Panama";
    bool result = Solution().BetterApproach(s);
    cout << result;

    return 0;
}