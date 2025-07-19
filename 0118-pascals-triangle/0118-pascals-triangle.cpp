class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.reserve(numRows);

        for (int rows = 0; rows < numRows; ++rows){
            vector<int> curr(rows + 1, 1);

            for (int j = 1; j < rows; ++j){
                curr[j] = triangle[rows - 1][j - 1] + triangle[rows - 1][j];
            }

            triangle.push_back(curr);
        }

        return triangle;
    }
};