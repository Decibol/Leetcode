class Solution {
public:
    void backtrack(int start, int target, int currSum, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result){
        if (currSum == target){
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i){
            if (currSum > target) break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            backtrack(i + 1, target, currSum + candidates[i], candidates, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        int currSum = 0;

        sort(candidates.begin(), candidates.end());

        backtrack(0, target, currSum, candidates, current, result);

        return result;
    }
};