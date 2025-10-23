class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if (r < 0 || r == board.size() || c < 0 || c == board[0].size() || board[r][c] != 'O' || visited[r][c]){
            return;
        }

        board[r][c] = 'S';
        visited[r][c] = true;

        dfs(r + 1, c, board, visited);
        dfs(r, c + 1, board, visited);
        dfs(r - 1, c, board, visited);
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
        
        for (int i = 0; i < n; ++i){
            if (board[0][i] == 'O') dfs(0, i, board, visited);
            if (board[m - 1][i] == 'O') dfs(m - 1, i, board, visited);
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                board[i][j] = board[i][j] == 'S' ? 'O' : 'X';
            }
        }
    }
};