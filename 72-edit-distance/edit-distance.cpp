class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
                               vector<int>(word2.size() + 1, -1));
        return solve(0, 0, word1, word2, dp);
    }

    int solve(int i, int j, string word1, string word2,
              vector<vector<int>>& dp) {

        if (i == word1.size()) {
            return word2.size() - j;
        }
        if (j == word2.size()) {
            return word1.size() - i;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return solve(i + 1, j + 1, word1, word2, dp);

        int Insert = 1 + solve(i, j + 1, word1, word2, dp);
        int Delete = 1 + solve(i + 1, j, word1, word2, dp);
        int Replace = 1 + solve(i + 1, j + 1, word1, word2, dp);

        return dp[i][j] = min({Insert, Delete, Replace});
    }
};