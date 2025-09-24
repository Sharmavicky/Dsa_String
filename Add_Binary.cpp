#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
    * Implements the solution for the "Add Binary" problem.
    * Given two binary strings, return their sum as a binary string.
    *
    * Methods:
    * 1. addBinary:
    *    - Iterates from the end of both strings, simulating binary addition.
    *    - Keeps track of carry while adding corresponding digits.
    *    - Uses character-to-integer conversion ('0' -> 0, '1' -> 1).
    *    - Appends result bits in reverse order, then reverses at the end.
    *
    * Example:
    *    a = "1010", b = "1011"
    *    Result = "10101"
    *
    * Complexity:
    *    - Time:  O(max(n, m))   where n, m = lengths of input strings
    *    - Space: O(max(n, m))   for storing the result string
*/

class Solution {
    public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        int i = a.size()-1, j = b.size()-1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// main function
int main() {
    string a = "11";
    string b = "1";

    string res = Solution().addBinary(a, b);
    cout << res;

    return 0;
}