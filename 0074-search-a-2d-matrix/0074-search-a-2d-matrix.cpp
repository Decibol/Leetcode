class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0, bottom = ROWS - 1;
        int row;

        while(top <= bottom){
            row = (top + bottom) / 2;

            if (target < matrix[row][0]){
                bottom = row - 1;
            }
            else if (target > matrix[row][COLS - 1]){
                top = row + 1;
            }
            else{
                break;
            }
        }

        int left = 0, right = COLS - 1;
        int mid;

        while (left <= right){
            mid = (left + right) / 2;

            if (target < matrix[row][mid]){
                right = mid - 1;
            }
            else if (target > matrix[row][mid]){
                left = mid + 1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};