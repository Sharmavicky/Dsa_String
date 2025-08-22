#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Time Complexity {
        1.BruteForce: O(n)
        2.BetterApproach: O(n)
        3.OptimalApproach: O(n)
    }

    Space Complexity {
        1.BruteForce: O(n)
        2.BetterApproach: Slightly Better but O(n)
        3.OptimalApproach: O(1)
    }
*/

class Solution {
    public:
    int BruteForce(string& s) {
        vector<string> strArr = {};
        string word = "";
        int length = s.size();

        for (int i=0; i<length; i++) {
            if (isalpha(s[i])) {
                word += s[i];
            } else if (s[i] == ' ' && word.size() > 0) {
                strArr.push_back(word);
                word = "";
            } else {
                continue;
            }
        }

        // Handling last word
        if (word.size() > 0) strArr.push_back(word);

        int arr_length = strArr.size();
        string lastWord = strArr[arr_length-1];
        return lastWord.size();
    }

    int BetterApproach(string& S) {
        string lastWord = "";
        int length = S.size();
        
        for(int i=length-1; i>=0; i--) {
            if (isalpha(S[i])) {
                lastWord += S[i];
            } else if (S[i] == ' ' && lastWord.size() > 0) {
                break;
            } else {
                continue;
            }
        }

        return lastWord.size();
    }

    int OptimalApproach(string& s) {
        int length = s.size(), i=length-1, count = 0;

        // loop through string until, we find the first word
        while (i >= 0 && s[i] == ' ') i--;

        // now count words from last to find the length of the last word
        while (i >= 0 && isalpha(s[i])) {
            count++;
            i--;
        }

        return count;
    }
};

// main function 
int main() {
    string S = "   fly me   to   the moon  ";
    int result = Solution().OptimalApproach(S);

    cout << result;

    return 0;
}