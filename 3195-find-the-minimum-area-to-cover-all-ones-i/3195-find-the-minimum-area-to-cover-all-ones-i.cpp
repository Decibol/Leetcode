class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int topRow = -1, bottomRow = -1;
        int leftCol = -1, rightCol = -1;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    topRow = i;
                    break;
                }
            }   
        }

        for (int i = m - 1; i >= 0; --i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    bottomRow = i;
                    break;
                }
            }
        }

        for (int j = 0; j < n; ++j){
            for (int i = 0; i < m; ++i){
                if (grid[i][j] == 1){
                    leftCol = j;
                    break;
                }
            }
        }

        for (int j = n - 1; j >= 0; --j){
            for (int i = 0; i < m; ++i){
                if (grid[i][j] == 1){
                    rightCol = j;
                    break;
                }
            }
        }   

        if (topRow == -1) return 0;

        int x = abs(bottomRow - topRow) + 1;
        int y = abs(leftCol - rightCol) + 1;

        return x * y;
    }
};