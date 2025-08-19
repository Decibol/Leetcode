class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result){
        if (start == nums.size()){
            result.push_back(nums);
        }

        unordered_set<int> used;
        for (int i = start; i < nums.size(); ++i){
            if (used.count(nums[i])) continue;

            used.insert(nums[i]);
            swap(nums[i], nums[start]);
            backtrack(start + 1, nums, result);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        backtrack(0, nums, result);

        return result;
    }
};