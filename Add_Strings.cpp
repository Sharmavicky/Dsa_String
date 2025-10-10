#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * This class implements a solution to the problem "Add Strings" (LeetCode #415).
    * Given two non-negative integers represented as strings, the addString() method
    * returns their sum as a string. The method simulates manual addition without converting
    * the entire strings into integers, which allows it to handle very large numbers.
    *
    * Method:
    * 1. addString(string num1, string num2):
    *    - Uses two pointers starting from the end of each string.
    *    - Adds corresponding digits along with any carry from the previous step.
    *    - Continues until all digits and any remaining carry are processed.
    *    - Builds the result string in reverse order, then reverses it before returning.
    *
    * Time Complexity: O(max(n, m)), where n and m are the lengths of num1 and num2.
    * Space Complexity: O(max(n, m)), for storing the result string.
    *
    * Example:
    * Input: num1 = "456", num2 = "77"
    * Output: "533"
*/

class Solution {
    public:
    string addString(string num1, string num2) {
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;

        string res = "";

        while (i >= 0 || j >= 0  || carry) {
            int digit_1 = i >= 0 ? num1[i] - '0' : 0;
            int digit_2 = j >= 0 ? num2[j] - '0' : 0;

            int  sum = digit_1 + digit_2 + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;

            i--;
            j--;
        }

        // reverse the result string
        reverse(res.begin(), res.end());

        return res;
    }
};

// main function
int main() {
    string n1 = "123";
    string n2 = "456";

    string res = Solution().addString(n1, n2);

    for (char c: res) {
        cout << c << " ";
    }

    return 0;
}