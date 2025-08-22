class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result){
        if (start == nums.size()){
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i){
            

            swap(nums[i], nums[start]);
            backtrack(start + 1, nums, result);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        backtrack(0, nums, result);

        return result;
    }
};