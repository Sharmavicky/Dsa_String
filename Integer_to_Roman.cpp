#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string intToRoman(int num) {
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string romanNumeral = "";

        for (const auto& pair: valueSymbols) {
            int value = pair.first;
            string symbol = pair.second;

            while (num >= value) {
                romanNumeral += symbol;
                num -= value;
            }
        }

        return romanNumeral;
    }
};

// main function
int main() {
    Solution sol;
    int number = 1994;
    cout << "Integer: " << number << " -> Roman Numeral: " << sol.intToRoman(number) << endl;
    return 0;
}