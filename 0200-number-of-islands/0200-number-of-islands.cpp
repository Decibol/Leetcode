class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if (r < 0 || r == grid.size() || c < 0 || c == grid[0].size() || visited[r][c] || grid[r][c] != '1'){
            return;
        }

        visited[r][c] = true;

        dfs(r + 1, c, grid, visited);
        dfs(r - 1, c, grid, visited);
        dfs(r, c + 1, grid, visited);
        dfs(r, c - 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == '1' && !visited[i][j]){
                    dfs(i, j, grid, visited);
                    ++count;
                }
            }
        }

        return count;
    }
};