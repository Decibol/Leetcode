class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int row = 0; row < rows; ++row){
            int left = 0, right = cols - 1;

            while (left <= right){
                int mid = (left + right) / 2;

                if (matrix[row][mid] == target){
                    return true;
                }
                else if (matrix[row][mid] < target){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};