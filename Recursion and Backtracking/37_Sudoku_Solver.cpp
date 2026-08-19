// LeetCode 37
// Sudoku Solver

class Solution {
public:
    bool isValid(int row, int col, char digit, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit)
                return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(row, col, digit, board)) {
                            board[row][col] = digit;

                            if (solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
