class Solution {
public:
    string sortVowels(string s) {
        string vstr = "";
        for (char ch : s) {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vstr += ch;
            }
        }
        sort(vstr.begin(), vstr.end());
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {

                s[i] = vstr[j];
                j++;
            }
        }
        return s;
    }
};