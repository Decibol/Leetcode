class Solution {
public:
    void backtrack(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& region, bool& solved){
        if (row == 9){
            solved = true;
            return;
        }

        int nextRow = (col == 8) ? row + 1 : row;
        int nextCol = (col == 8) ? 0 : col + 1;

        if (board[row][col] != '.'){
            backtrack(nextRow, nextCol, board, rows, cols, region, solved);
            return;
        }

        int regionIndex = (row / 3)*3 + (col/3);

        for (int i = 0; i < 9; ++i){
            if (rows[row][i] || cols[col][i] || region[regionIndex][i]) continue;

            board[row][col] = '0' + i + 1;
            rows[row][i] = true;
            cols[col][i] = true;
            region[regionIndex][i] = true;

            backtrack(nextRow, nextCol, board, rows, cols, region, solved);
            if (solved) return;

            board[row][col] = '.';
            rows[row][i] = false;
            cols[col][i] = false;
            region[regionIndex][i] = false;    
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> region(9, vector<bool>(9, false));
        bool solved = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int regionIdx = (i / 3) * 3 + (j / 3);
                    rows[i][num] = cols[j][num] = region[regionIdx][num] = true;
                }
            }
        }
        
        backtrack(0, 0, board, rows, cols, region, solved);
    }
};