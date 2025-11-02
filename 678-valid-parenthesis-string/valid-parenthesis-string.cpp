class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solve(s, 0, 0, dp);
        return solve1(s, s.size());
    }

    // top down;
    // bool solve(string s, int open, int idx, vector<vector<int>>& dp) {
    //     if (idx == s.size())
    //         return open == 0;

    //     if (dp[idx][open] != -1)
    //         return dp[idx][open];

    //     bool isValid = false;

    //     if (s[idx] == '(') {
    //         isValid = solve(s, open + 1, idx + 1, dp);
    //     } else if (s[idx] == '*') {
    //         isValid |= solve(s, open + 1, idx + 1, dp); // for open Bracket
    //         isValid |= solve(s, open, idx + 1, dp);     // for empty
    //         if (open > 0)                               // for close Bracket
    //             isValid |= solve(s, open - 1, idx + 1, dp);
    //     } else if (open > 0) {
    //         isValid |= solve(s, open - 1, idx + 1, dp);
    //     }
    //     return dp[idx][open] = isValid;
    // }

    // bottom up
    bool solve1(string& s, int n) {
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));

        // Base case: at the end, only open==0 is valid
        t[n][0] = true;

        // Fill table backwards
        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;
                if (s[i] == '(') {
                    if (open + 1 <= n)
                        isValid = t[i + 1][open + 1];
                } else if (s[i] == '*') {
                    if (open + 1 <= n)
                        isValid |= t[i + 1][open + 1]; // treat * as '('
                    isValid |= t[i + 1][open];         // treat * as empty
                    if (open > 0)
                        isValid |= t[i + 1][open - 1]; // treat * as ')'
                } else if (s[i] == ')') {
                    if (open > 0)
                        isValid = t[i + 1][open - 1];
                }

                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
};