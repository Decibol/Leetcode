class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        if (start == nums.size()){
            result.push_back(current);
        }

        for (int i = start; i < nums.size(); ++i){
            swap(nums[i], nums[start]);
            current.push_back(nums[start]);
            backtrack(start + 1, nums, current, result);
            current.pop_back();
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        
        backtrack(0, nums, current, result);
        
        return result;
    }
};