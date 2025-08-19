class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result){
        if (current.size() == k){
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i){
            current.push_back(i);
            backtrack(i + 1, k, n, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(1, k, n, current, result);

        return result;
    }
};