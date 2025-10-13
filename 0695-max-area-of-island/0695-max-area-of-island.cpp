class Solution {
public:
    void dfs(int r, int c, int& area, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if (r < 0 || r == grid.size() || c < 0 || c == grid[0].size() || grid[r][c] != 1 || visited[r][c]){
            return;
        }

        visited[r][c] = true;
        ++area;

        dfs(r + 1, c, area, grid, visited);
        dfs(r - 1, c, area, grid, visited);
        dfs(r, c + 1, area, grid, visited);
        dfs(r, c - 1, area, grid, visited);
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
                    dfs(i, j, area, grid, visited);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};