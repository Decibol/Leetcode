class Solution {
public:
    void backtrack(int start, int k, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        if (current.size() == k){
            result.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); ++i){
            current.push_back(nums[i]);
            backtrack(i + 1, k, nums, current, result);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1); 

        backtrack(0, k, nums, current, result);

        return result;
    }
};