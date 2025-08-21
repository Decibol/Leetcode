class Solution {
public:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& posDiagonal, vector<bool>& negDiagonal, vector<vector<string>>& result){
        if (row == n){
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col){
            if (cols[col] || posDiagonal[row + col] || negDiagonal[row - col + n - 1]) continue;

            cols[col] = true;
            posDiagonal[row + col] = true;
            negDiagonal[row - col + n - 1] = true;
            board[row][col] = 'Q';

            backtrack(row + 1, n, board, cols, posDiagonal, negDiagonal, result);

            cols[col] = false;
            posDiagonal[row + col] = false;
            negDiagonal[row - col + n - 1] = false;
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> posDiagonal(2*n - 1, false);
        vector<bool> negDiagonal(2*n - 1, false);
        vector<vector<string>> result;

        backtrack(0, n, board, cols, posDiagonal, negDiagonal, result);

        return result;
    }
};