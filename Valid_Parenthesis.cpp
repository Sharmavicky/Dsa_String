#include <bits/stdc++.h>
#include <stack>
using namespace std;

/*
    * @class Solution
    * @brief Implements two approaches to validate whether a string of brackets is balanced.
    *
    * The class provides two methods:
    *
    * 1. **BruteForce()**
    *      - Uses a straightforward stack-based check for valid parentheses.
    *      - For every closing bracket, it verifies that the top of the stack contains
    *        the correct corresponding opening bracket.
    *      - Returns false immediately on mismatch or if the stack is empty when
    *        encountering a closing bracket.
    *
    * 2. **Optimal()**
    *      - A clean and structured version of the same stack-based logic.
    *      - Pops the top element for each closing bracket and checks bracket compatibility
    *        using clear conditional comparisons.
    *      - Ensures all brackets are matched by verifying the stack is empty at the end.
    *
    * Both methods run in **O(n)** time and **O(n)** space, making them suitable for
    * syntax checking, expression parsing, and balanced bracket validation problems.
*/

class Solution {
public:
    bool BruteForce(string s) {
        stack<char> stk;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.size() == 0) return false;

                if (stk.top() == '(' && c == ')' || stk.top() == '{' && c == '}' || stk.top() == '[' && c == ']') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.size() == 0;
    }

    bool Optimal(string s) {
        stack<char> stk;

        for (char c : s) {
            // If it's an opening bracket, push
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            else{
                // If closing bracket but stack empty → invalid
                if (stk.empty()) return false;

                char top = stk.top();
                stk.pop();

                // Check if the brackets match
                if ((top == '(' && c != ')') ||
                    (top == '{' && c != '}') ||
                    (top == '[' && c != ']'))
                {
                    return false;
                }
            }
        }

        // If stack empty, all brackets correctly matched
        return stk.empty();
    }
};