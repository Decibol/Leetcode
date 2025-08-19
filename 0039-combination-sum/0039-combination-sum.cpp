class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, int currSum, vector<int>& current, vector<vector<int>>& result){
        if (currSum == target){
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i){
            if (currSum > target) break;

            current.push_back(candidates[i]);
            backtrack(i, target, candidates, currSum + candidates[i], current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        int currSum = 0;

        backtrack(0, target, candidates, currSum, current, result);

        return result;
    }
};