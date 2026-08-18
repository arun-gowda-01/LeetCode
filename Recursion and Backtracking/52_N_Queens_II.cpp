// LeetCode 52
// N-Queens II

class Solution {
public:
    bool isValid(int row, int col, int n, vector<string>& board) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n, board)) {
                board[row][col] = 'Q';

                solve(row + 1, n, board, count);

                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));

        solve(0, n, board, count);

        return count;
    }
};
