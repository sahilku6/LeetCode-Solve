class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            if (isvowel(ch)) {
                mp[ch]++;
            }
        }

        int j = 0;
        string temp = "AEIOUaeiou";

        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                while (mp[temp[j]] == 0) {
                    j++;
                }
                s[i] = temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
    }

private:
    bool isvowel(char ch) {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
};