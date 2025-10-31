class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if (r < 0 || r == grid.size() || c < 0 || c == grid[0].size() || visited[r][c] || grid[r][c] != 1) return;

        visited[r][c] = true;

        dfs(r + 1, c, grid, visited);
        dfs(r - 1, c, grid, visited);
        dfs(r, c + 1, grid, visited);
        dfs(r, c - 1, grid, visited);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i){
            if (grid[i][0] == 1) dfs(i, 0, grid, visited);
            if (grid[i][n - 1] == 1) dfs(i, n - 1, grid, visited);
        }

        for (int j = 0; j < n; ++j){
            if (grid[0][j] == 1) dfs(0, j, grid, visited);
            if (grid[m - 1][j] == 1) dfs(m - 1, j, grid, visited);
        }

        int count = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1 && !visited[i][j]){
                    ++count;
                }
            }
        }

        return count;
    }
};