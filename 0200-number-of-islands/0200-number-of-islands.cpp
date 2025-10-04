class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<pair<int, int>>& directions,  vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1' && !visited[nr][nc]){
                    visited[nr][nc] = true;

                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {1, 0}};
        int count = 0;

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == '1' && !visited[i][j]){
                    bfs(i, j, grid, directions, visited);
                    ++count;
                }
            }
        }

        return count;
    }
};