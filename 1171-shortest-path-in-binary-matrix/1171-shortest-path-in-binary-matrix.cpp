class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0] == 0 ? 1 : -1;
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        visited[0][0] = true;

        while (!q.empty()){
            auto [r, c, dist] = q.front();
            q.pop();

            for (auto const& [dr, dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr == n || nc < 0 || nc == n || visited[nr][nc] || grid[nr][nc] == 1) continue;
                
                if (nr == grid.size() - 1 && nc == grid.size() - 1){
                    return dist + 1;
                }

                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }

        return -1;
    }
};