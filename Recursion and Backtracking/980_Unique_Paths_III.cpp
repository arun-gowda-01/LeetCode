// LeetCode 980
// Unique Paths III

class Solution {
public:
    void solve(int row, int column, int m, int n, int visitedCount,
               int totalNonObstacles, int& count,
               vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if (row < 0 || row >= m || column < 0 || column >= n)
            return;

        if (grid[row][column] == -1)
            return;

        if (visited[row][column])
            return;

        visited[row][column] = 1;
        visitedCount++;

        if (grid[row][column] == 2) {
            if (visitedCount == totalNonObstacles)
                count++;

            visited[row][column] = 0;
            return;
        }

        solve(row - 1, column, m, n, visitedCount, totalNonObstacles, count, grid, visited);
        solve(row + 1, column, m, n, visitedCount, totalNonObstacles, count, grid, visited);
        solve(row, column - 1, m, n, visitedCount, totalNonObstacles, count, grid, visited);
        solve(row, column + 1, m, n, visitedCount, totalNonObstacles, count, grid, visited);

        visited[row][column] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0, totalNonObstacles = 0;
        int startRow, startCol;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    totalNonObstacles++;

                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        solve(startRow, startCol, m, n, 0, totalNonObstacles,
              count, grid, visited);

        return count;
    }
};
