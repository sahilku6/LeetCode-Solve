class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));

        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 2;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    markGuarded(grid, i, j, m, n);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    count++;
                }
            }
        }
        return count;
    }

    void markGuarded(vector<vector<int>>& grid, int row, int col, int m,
                     int n) {
        // up
        for (int i = row - 1; i >= 0 && grid[i][col] != 2 && grid[i][col] != 1;
             i--)
            grid[i][col] = 0;
        // down
        for (int i = row + 1; i < m && grid[i][col] != 2 && grid[i][col] != 1;
             i++)
            grid[i][col] = 0;
        // left
        for (int j = col - 1; j >= 0 && grid[row][j] != 2 && grid[row][j] != 1;
             j--)
            grid[row][j] = 0;
        // right
        for (int j = col + 1; j < n && grid[row][j] != 2 && grid[row][j] != 1;
             j++)
            grid[row][j] = 0;
    }
};
