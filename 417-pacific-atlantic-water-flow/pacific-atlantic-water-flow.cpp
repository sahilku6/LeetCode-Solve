class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        if (heights.size() == 0)
            return ans;

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0, INT_MIN);      // left
            dfs(heights, atlantic, i, m - 1, INT_MIN); // right
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i, INT_MIN);      // top
            dfs(heights, atlantic, n - 1, i, INT_MIN); // bottom
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        };
        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int row,
             int col, int prev) {
        int n = heights.size();
        int m = heights[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || ocean[row][col] ||
            heights[row][col] < prev) {
            return;
        }

        ocean[row][col] = 1;
        prev = heights[row][col];

        dfs(heights, ocean, row - 1, col, prev); // top
        dfs(heights, ocean, row, col + 1, prev); // right
        dfs(heights, ocean, row + 1, col, prev); // bottom
        dfs(heights, ocean, row, col - 1, prev); // left
    }
};