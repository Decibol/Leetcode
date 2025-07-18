class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); ++i){
            currentMax = max(nums[i], currentMax + nums[i]);
            globalMax = max(currentMax, globalMax);
        }
        
        return globalMax;
    }
};