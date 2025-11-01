class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool hasA = false, hasB = false, hasC = false;
        int x = target[0], y = target[1], z = target[2];

        for (auto &t : triplets) {
            int a = t[0], b = t[1], c = t[2];
            if (a > x || b > y || c > z) continue;

            if (a == x) hasA = true;
            if (b == y) hasB = true;
            if (c == z) hasC = true;
        }

        return hasA && hasB && hasC;
    }
};
