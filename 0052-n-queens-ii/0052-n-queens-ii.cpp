class Solution {
public:
    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& posDiagonal, vector<bool>& negDiagonal, int& result){
        if (row == n){
            result++;
            return;
        }

        for (int col = 0; col < n; ++col){
            if (cols[col] || posDiagonal[row + col] || negDiagonal[row - col + n - 1]) continue;

            cols[col] = true;
            posDiagonal[row + col] = true;
            negDiagonal[row - col + n - 1] = true;

            backtrack(row + 1, n, cols, posDiagonal, negDiagonal, result);

            cols[col] = false;
            posDiagonal[row + col] = false;
            negDiagonal[row - col + n - 1] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> posDiagonal(2*n - 1, false);
        vector<bool> negDiagonal(2*n - 1, false);
        int result = 0;

        backtrack(0, n, cols, posDiagonal, negDiagonal, result);

        return result;
    }
};