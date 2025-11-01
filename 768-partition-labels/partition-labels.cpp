class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;

        vector<int> mp(26, -1);

        // store last ocuurence
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            mp[idx] = i;
        }

        int i = 0;
        int end = 0;
        int start = 0;
        while (i < n) {
            end = max(end, mp[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return res;
    }
};