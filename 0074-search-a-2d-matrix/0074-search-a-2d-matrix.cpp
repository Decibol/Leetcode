class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bottom = rows - 1;
        int row;
        while (top <= bottom){
            row = (top + bottom) / 2;

            if (target < matrix[row][0]){
                bottom = row - 1;
            }
            else if (target > matrix[row][cols - 1]){
                top = row + 1;
            }
            else{
                break;
            }
        }

        int left = 0, right = cols - 1;
        int col;

        while (left <= right){
            col = (left + right) / 2;

            if (target < matrix[row][col]){
                right = col - 1;
            }
            else if (target > matrix[row][col]){
                left = col + 1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};