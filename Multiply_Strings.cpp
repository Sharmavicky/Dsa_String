#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * This class provides a solution to the problem "Multiply Strings" (LeetCode #43).
    * Given two non-negative integers represented as strings, the multiplyString() method
    * returns their product as a string. The method simulates manual multiplication without
    * converting the entire strings into integers, which allows it to handle arbitrarily large numbers.
    *
    * Method:
    * 1. multiplyString(string num1, string num2):
    *    - Initializes a result array of size n + m (maximum possible digits).
    *    - Loops through each digit of num1 and num2 in reverse order.
    *    - Multiplies corresponding digits and adds any existing value at the position.
    *    - Handles carry and stores digits in the result array.
    *    - Converts the result array to a string and removes leading zeros.
    *
    * Time Complexity: O(n * m), where n = num1.length() and m = num2.length().
    * Space Complexity: O(n + m), for storing the result array.
    *
    * Example:
    * Input: num1 = "123", num2 = "45"
    * Output: "5535"
*/

class Solution {
    public:
    string multiplyString(string num1,  string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        // Multiply each digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10; // position where we have to update value after multiplication
                res[i + j] += sum / 10;
            }
        }

        // Convert result array to string
        string result = "";
        for (int num : res) result += (num + '0');

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') start++;

        return start == result.size() ? "0" : result.substr(start);
    }
};

// main function
int main() {
    string n1 = "123";
    string n2 = "456";

    string res = Solution().multiplyString(n1, n2);

    for (char c: res) {
        cout << c << " ";
    }

    return 0;
}