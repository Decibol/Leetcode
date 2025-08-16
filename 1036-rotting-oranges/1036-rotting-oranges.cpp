class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int fresh_count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                else if (grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty() && fresh_count > 0){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int row = r + dr;
                    int col = c + dc;

                    if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] != 1) continue;

                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh_count--;
                }
            }

            minutes++;
        }

        return fresh_count != 0 ? -1 : minutes;
    }
};