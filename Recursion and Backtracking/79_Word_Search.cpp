// LeetCode 79
// Word Search

class Solution {
public:
    bool solve(int row, int column, int m, int n, int wordIndex,
               vector<vector<char>>& board, string& word,
               vector<vector<int>>& visited) {
        if (word.size() == wordIndex)
            return true;

        if (row < 0 || row >= m || column < 0 || column >= n)
            return false;

        if (board[row][column] != word[wordIndex])
            return false;

        if (visited[row][column])
            return false;

        visited[row][column] = 1;

        bool found = solve(row - 1, column, m, n, wordIndex + 1, board, word, visited) ||
                     solve(row + 1, column, m, n, wordIndex + 1, board, word, visited) ||
                     solve(row, column - 1, m, n, wordIndex + 1, board, word, visited) ||
                     solve(row, column + 1, m, n, wordIndex + 1, board, word, visited);

        visited[row][column] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, m, n, 0, board, word, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
