class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;

        for (int i = 0; i <= rowIndex; ++i){
            vector<int> current(i + 1, 1);

            for (int j = 1; j < current.size() - 1; ++j){
                current[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(current);

            if (current.size() == rowIndex + 1) return current;
        }

        return {};
    }
};