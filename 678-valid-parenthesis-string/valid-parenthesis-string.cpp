class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s, 0, 0, dp);
    }

    bool solve(string s, int open, int idx, vector<vector<int>>& dp) {
        if (idx == s.size())
            return open == 0;

        if (dp[idx][open] != -1)
            return dp[idx][open];
        bool isValid = false;

        if (s[idx] == '(') {
            isValid = solve(s, open + 1, idx + 1, dp);
        } else if (s[idx] == '*') {
            isValid |= solve(s, open + 1, idx + 1, dp); // for open Bracket
            isValid |= solve(s, open, idx + 1, dp);     // for empty
            if (open > 0)                               // for close Bracket
                isValid |= solve(s, open - 1, idx + 1, dp);
        } else if (open > 0) {
            isValid |= solve(s, open - 1, idx + 1, dp);
        }
        return dp[idx][open] = isValid;
    }
};