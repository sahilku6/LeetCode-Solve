#include <unordered_map>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> mpV;
        unordered_map<char, int> mpC;
        priority_queue<int> pqVowel;
        priority_queue<int> pqConso;

        for (char ch : s) {
            ch = tolower(ch);
            if (isVowel(ch)) {
                mpV[ch]++;
            } else if (isalpha(ch)) {
                mpC[ch]++;
            }
        }

        for (auto [_, freq] : mpV) {
            pqVowel.push(freq);
        }
        for (auto [_, freq] : mpC) {
            pqConso.push(freq);
        }

        int maxVowel = pqVowel.empty() ? 0 : pqVowel.top();
        int maxConso = pqConso.empty() ? 0 : pqConso.top();

        return maxVowel + maxConso;
    }
};
