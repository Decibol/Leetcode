class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;

        int m = mat.size();
        int n = mat[0].size();
        int direction = 1;

        for (int col = 0; col < n; ++col){
            vector<int> current;

            int row = 0;
            int currentCol = col;

            while (row <= col && row < m && currentCol >= 0){
                current.push_back(mat[row][currentCol]);
                currentCol--;
                row++;
            }

            if (direction == 1){
                reverse(current.begin(), current.end());
            }

            result.insert(result.end(), current.begin(), current.end());
            direction *= -1;
        }

        for (int row = 1; row < m; ++row){
            vector<int> current;
            int col = n - 1;
            int currentRow = row;

            while (col >= 0 && currentRow < m){
                current.push_back(mat[currentRow][col]);
                col--;
                currentRow++;
            }

            if (direction == 1){
                reverse(current.begin(), current.end());
            }

            result.insert(result.end(), current.begin(), current.end());
            direction *= -1;
        }

        return result;
    }
};