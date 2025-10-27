#include <bits/stdc++.h>
#include <stack>
using namespace std;

/*
    * @class Solution
    * @brief Provides a method to validate if a given string of parentheses is balanced.
    *
    * This class implements the classic "Valid Parentheses" problem using a stack-based approach.
    * The algorithm ensures that every opening bracket ('(', '{', '[') has a corresponding
    * closing bracket (')', '}', ']') and that the order of brackets is correctly nested.
    *
    * Approach:
    * - Traverse the input string character by character.
    * - Push all opening brackets onto a stack.
    * - For every closing bracket, check if it correctly matches the top of the stack.
    * - If at any point there’s a mismatch or an extra closing bracket, return false.
    * - Finally, the string is valid if the stack is empty.
    *
    * Time Complexity: O(N)
    * Space Complexity: O(N)
    *
    * Example:
    * Input: "{[()]}"
    * Output: true
*/

class Solution {
public:
    bool isValid(string s) {
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
};