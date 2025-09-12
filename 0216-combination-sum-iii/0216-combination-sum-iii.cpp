class Solution {
public:
    void backtrack(int start, int sum, int& k, int& n, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result){
        if (sum == n && current.size() == k){
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i){
            if (sum > n || current.size() > k) return;

            current.push_back(candidates[i]);
            backtrack(i + 1, sum + candidates[i], k, n, candidates, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates(9);
        iota(candidates.begin(), candidates.end(), 1);

        vector<int> current;
        vector<vector<int>> result;

        backtrack(0, 0, k, n, candidates, current, result);

        return result;
    }
};