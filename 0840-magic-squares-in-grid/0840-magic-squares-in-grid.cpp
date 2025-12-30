class Solution {
public:
    bool isMagic(int r, int c, vector<vector<int>>& grid){
        bitset<10> seen;

        for (int i = r; i < r + 3; ++i){
            for (int j = c; j < c + 3; ++j){
                if (grid[i][j] < 0 || grid[i][j] > 9 || seen[grid[i][j]]) return false;
                
                seen.flip(grid[i][j]);
            }
        }

        if (grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != 15) return false;

        if (grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != 15) return false;

        if (grid[r][c] + grid[r][c + 1] + grid[r][c + 2] != 15) return false;

        if (grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != 15) return false;

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) return false;

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m < 3 || n < 3) return 0;

        int count = 0;

        for (int i = 0; i <= m - 3; ++i){
            for (int j = 0; j <= n - 3; ++j){
                if (grid[i + 1][j + 1] == 5 && isMagic(i, j, grid)) ++count;
            }
        }
        
        return count;
    }
};