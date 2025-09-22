class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int longest = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest = max(longest, dfs(i, j, n, m, matrix, dp));
            }
        }
        return longest;
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int maxPath = 1;
        vector<pair<int,int>> dir{{0,-1},{0,1},{-1,0},{1,0}};

        for (auto [dx, dy] : dir) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(ni, nj, n, m, matrix, dp));
            }
        }
        return dp[i][j] = maxPath; 
    }
};
