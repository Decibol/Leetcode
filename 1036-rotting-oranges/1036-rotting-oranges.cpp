class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == 1) ++fresh;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty() && fresh > 0){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size() || grid[nr][nc] != 1) continue;

                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    --fresh;
                }
            }

            ++time;
        }

        return fresh != 0 ? -1 : time;
    }
};