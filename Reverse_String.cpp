#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void reverseStr(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

// main function
int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    cout << "after reversing the string: \n";
    Solution().reverseStr(s);

    for (char ch: s) {
        cout << ch << " ";
    }

    return 0;
}