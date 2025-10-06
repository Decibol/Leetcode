class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if (r < 0 || r == board.size() || c < 0 || c == board[0].size() || visited[r][c] || board[r][c] != 'O'){
            return;
        }

        visited[r][c] = true;
        board[r][c] = 'S';

        dfs(r + 1, c, board, visited);
        dfs(r - 1, c, board, visited);
        dfs(r, c + 1, board, visited);
        dfs(r, c - 1, board, visited);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i){
            if (board[i][0] == 'O') dfs(i, 0, board, visited);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board, visited);
        }

        for (int j = 0; j < n; ++j){
            if (board[0][j] == 'O') dfs(0, j, board, visited);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board, visited);
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                board[i][j] = board[i][j] == 'S' ? 'O' : 'X';
            }
        }
    }
};