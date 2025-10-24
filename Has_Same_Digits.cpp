#include <bits/stdc++.h>
using namespace std;

/*
    Class: hasSameDigit

    This class provides a method to determine whether a given numeric string
    ultimately reduces to two identical digits after repeatedly performing
    the following operation:

    - Replace the string with a new string formed by taking the sum of every
      pair of adjacent digits, keeping only the last digit of each sum
      (i.e., (a + b) % 10).

    The process continues until the string’s length becomes 2.
    The final result returns true if both remaining digits are the same,
    otherwise false.

    Example:
        Input: "1234"
        Step 1: (1+2)%10=3, (2+3)%10=5, (3+4)%10=7 → "357"
        Step 2: (3+5)%10=8, (5+7)%10=2 → "82"
        Output: false  (since '8' != '2')
*/

class hasSameDigit {
    public:
    bool BruteForce(string s) {
        while (s.length() != 2) {
            string new_s = "";

            for (int i=0; i<s.length()-1; i++) {
                int first = s[i] - '0';
                int second = s[i+1] - '0';
                new_s += ((first + second) % 10) + '0';
            }

            s = new_s;
        }

        return s[0] == s[1];
    }
};

// main function
int main() {
    string s = "3902";
    bool res = hasSameDigit().BruteForce(s);
    cout << res;
    return 0;
}