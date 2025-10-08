class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area){
        if (r < 0 || r == grid.size() || c < 0 || c == grid[0].size() || visited[r][c] || grid[r][c] != 1){
            return;
        }

        ++area;
        visited[r][c] = true;

        dfs(r + 1, c, grid, visited, area);
        dfs(r - 1, c, grid, visited, area);
        dfs(r, c + 1, grid, visited, area);
        dfs(r, c - 1, grid, visited, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxArea = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1 && !visited[i][j]){
                    int area = 0;
                    dfs(i, j, grid, visited, area);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};