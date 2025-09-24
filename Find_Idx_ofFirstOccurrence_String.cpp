#include <iostream>
#include <string>
using namespace std;

/*
    * This class provides different methods to solve the classic
    * "Find the Index of the First Occurrence in a String" problem.
    *
    * Methods:
    * 1. BruteForce:
    *    - Checks every possible substring of `haystack` with length equal to `needle`.
    *    - Returns the starting index if a match is found, otherwise returns -1.
    *    - Time Complexity: O(n * m), where n = haystack length, m = needle length.
    *    - Space Complexity: O(1) (ignoring substring overhead).
    *
    * 2. Optimal:
    *    - Utilizes C++ built-in `string::find()` function.
    *    - Returns the index of the first occurrence of `needle` in `haystack`.
    *    - If not found, returns -1.
    *    - Time Complexity: Typically O(n + m), depending on implementation.
    *    - Space Complexity: O(1).
    *
    * Overall:
    * - Demonstrates both a naive and optimal approach for substring search.
    * - Useful for understanding the trade-offs between manual implementation
    *   and leveraging standard library functions.
*/

class Solution {
    public:
    int BruteForce(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;

        for (int i=0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) return i;
        }

        return -1;
    }

    int Optimal(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// main function
int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    int res = Solution().BruteForce(haystack, needle);

    cout << res;
    return 0;
}