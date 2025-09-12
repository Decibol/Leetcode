class Solution {
public:
    void backtrack(int start, int& target, int sum, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result){
        if (sum == target){
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i){
            if (sum > target) return;
            
            current.push_back(candidates[i]);
            backtrack(i, target, sum + candidates[i], candidates, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(0, target, 0, candidates, current, result);

        return result;
    }
};