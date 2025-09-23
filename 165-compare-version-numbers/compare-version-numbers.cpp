class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = getToken(version1);
        vector<string> v2 = getToken(version2);
        int v1Size = v1.size();
        int v2Size = v2.size();
        int maxSize = max(v1Size, v2Size);

        for (int i = 0; i < maxSize; i++) {
            int a = (i < v1Size ? stoi(v1[i]) : 0);
            int b = (i < v2Size ? stoi(v2[i]) : 0);

            if (a > b)
                return 1;
            if (a < b)
                return -1;
        }
        return 0;
    }

private:
    vector<string> getToken(string str) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, '.')) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
