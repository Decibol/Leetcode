class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh_count = 0;
        queue<pair<int, int>> q;

        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                if (grid[r][c] == 2){
                    q.push({r, c});
                }
                if (grid[r][c] == 1){
                    fresh_count += 1;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty() && fresh_count > 0){
            int size = q.size();
            for (int i = 0; i < size; ++i){
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions){
                    int row = r + dr;
                    int col = c + dc;

                    if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] != 1){
                        continue;
                    }
                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh_count -= 1;
                }
            }
            minutes++;
        }
        return (fresh_count == 0) ? minutes : -1;
    }
};