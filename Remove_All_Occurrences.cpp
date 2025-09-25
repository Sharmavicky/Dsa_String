#include <iostream>
#include <string>
using namespace std;

/*
    * Class Solution provides a method to remove all occurrences of a given substring
    * (part) from the input string (s). The approach repeatedly searches for the 
    * substring using std::string::find and erases it until no more matches exist.
    * 
    * Time Complexity: O(n * m) in the worst case, where n = length of s and m = length of part.
    * Space Complexity: O(1), as modifications are done in-place.
*/

class Solution {
    public:
    string removeAllOccurrence(string& s, string& part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }

        return s;
    }
};

// main function
int main() {
    string s = "daccddfdbabc";
    string part = "abc";

    string res = Solution().removeAllOccurrence(s, part);
    cout << res;

    return 0;
}