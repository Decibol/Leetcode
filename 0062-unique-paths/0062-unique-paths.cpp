class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);

        for (int i = 1; i < m; ++i){
            for (int j = n - 2; j > -1; --j){
                row[j] += row[j + 1];
            }
        }

        return row[0];
    }
};