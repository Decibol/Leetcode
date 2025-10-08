class Solution {
public:
    void bfs(int& row, int& col, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& directions){
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for (auto const& [dr, dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size() || visited[nr][nc] || grid[nr][nc] != '1') continue;

                visited[nr][nc] = true;

                q.push({nr, nc});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, grid, visited, directions);
                    ++count;
                }
            }
        }

        return count;
    }
};