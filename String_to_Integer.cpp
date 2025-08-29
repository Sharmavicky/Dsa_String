#include <iostream>
#include <string>
using namespace std;

/*
    * Function: BruteForce
    * ---------------------
    * Converts a given string into an integer (similar to the C/C++ "atoi" function).
    *
    * Steps:
    *  1. Ignores any leading whitespace.
    *  2. Checks for an optional '+' or '-' sign to determine the number's sign.
    *  3. Reads consecutive digits and builds the integer value.
    *  4. Handles integer overflow/underflow:
    *       - If the number exceeds INT32_MAX, it returns INT32_MAX.
    *       - If the number goes below INT32_MIN, it returns INT32_MIN.
    *  5. Stops parsing at the first non-digit character after optional sign/digits.
    *
    * Example:
    *  Input:  "   -42"
    *  Output: -42
    *
    *  Input:  "4193 with words"
    *  Output: 4193
*/


class Solution {
    public:
    int BruteForce(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long num = 0;
        // skip character if they are not integers or a whitespace
        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            
            if (sign == 1 && num > INT32_MAX) return INT32_MAX;
            if (sign == -1 && -num < INT32_MIN) return INT32_MIN;
            
            i++;
        }

        return (int)(sign*num);
    }
};

// main function
int main() {
    string S = "  0-1";
    int result = Solution().BruteForce(S);

    cout << result;
    return 0;
}