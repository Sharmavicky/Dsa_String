#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
    int findIdxStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// main function
int main() {
    string haystack = "sadbutsad";
    string needle = "sad";

    int res = Solution().findIdxStr(haystack, needle);

    cout << res;
    return 0;
}