class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exactMatch(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelErrorMap;

        for (string word : wordlist) {
            string wordLower = toLower(word);

            if (caseInsensitive.find(wordLower) == caseInsensitive.end())
                caseInsensitive[wordLower] = word;

            string wordVowelError = devowel(wordLower);
            if (vowelErrorMap.find(wordVowelError) == vowelErrorMap.end())
                vowelErrorMap[wordVowelError] = word;
        }

        vector<string> res;
        for (string query : queries) {
            if (exactMatch.count(query)) {
                res.push_back(query);
                continue;
            }

            string queryLower = toLower(query);
            if (caseInsensitive.count(queryLower)) {
                res.push_back(caseInsensitive[queryLower]);
                continue;
            }

            string queryVowelError = devowel(queryLower);
            if (vowelErrorMap.count(queryVowelError)) {
                res.push_back(vowelErrorMap[queryVowelError]);
                continue;
            }

            res.push_back("");
        }

        return res;
    }

private:
    string toLower(const string& word) {
        string result;
        for (char ch : word)
            result += tolower(ch);
        return result;
    }

    string devowel(const string& word) {
        string result;
        for (char ch : word) {
            if (isVowel(ch))
                result += '*';
            else
                result += ch;
        }
        return result;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
