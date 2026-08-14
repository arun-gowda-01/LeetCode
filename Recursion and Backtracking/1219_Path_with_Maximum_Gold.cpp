// LeetCode 1219
// Path with Maximum Gold

class Solution {
public:
    void solve(int row, int column, int m, int n, int& currentGold,
               int& maxGold, vector<vector<int>>& grid,
               vector<vector<int>>& visited) {
        if (row < 0 || row >= m || column < 0 || column >= n)
            return;

        if (grid[row][column] == 0)
            return;

        if (visited[row][column])
            return;

        visited[row][column] = 1;
        currentGold += grid[row][column];

        maxGold = max(maxGold, currentGold);

        solve(row - 1, column, m, n, currentGold, maxGold, grid, visited);
        solve(row + 1, column, m, n, currentGold, maxGold, grid, visited);
        solve(row, column - 1, m, n, currentGold, maxGold, grid, visited);
        solve(row, column + 1, m, n, currentGold, maxGold, grid, visited);

        currentGold -= grid[row][column];
        visited[row][column] = 0;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0, currentGold = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    solve(i, j, m, n, currentGold, maxGold, grid, visited);
            }
        }

        return maxGold;
    }
};
