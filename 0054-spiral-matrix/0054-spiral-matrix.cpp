class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        while (left < right && top < bottom){
            for (int i = left; i < right; ++i){
                result.push_back(matrix[top][i]);
            }

            ++top;

            for (int j = top; j < bottom; ++j){
                result.push_back(matrix[j][right - 1]);
            }

            --right;
            if (top < bottom){
                for (int i = right - 1; i >= left; --i){
                    result.push_back(matrix[bottom - 1][i]);
                }
            }

            --bottom;

            if (left < right){
                for (int j = bottom - 1; j >= top; --j){
                    result.push_back(matrix[j][left]);
                }
            }

            ++left;
        }

        return result;
    }
};