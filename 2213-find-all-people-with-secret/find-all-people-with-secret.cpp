class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];

            vector<pair<int,int>> cur;
            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                cur.push_back({meetings[j][0], meetings[j][1]});
                j++;
            }

            bool changed = true;
            while (changed) {
                changed = false;
                for (auto &p : cur) {
                    int x = p.first;
                    int y = p.second;
                    if (knows[x] && !knows[y]) {
                        knows[y] = true;
                        changed = true;
                    }
                    if (knows[y] && !knows[x]) {
                        knows[x] = true;
                        changed = true;
                    }
                }
            }

            i = j;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (knows[i]) res.push_back(i);
        }
        return res;
    }
};
