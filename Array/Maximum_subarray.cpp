class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // DONE USING KADANE'S ALGORITHM
        int currentMax = nums[0];
        int globalMax = nums[0];

        int n = nums.size();

        for(int i = 1; i < n; i++){
            currentMax = max(nums[i], currentMax + nums[i]); // If the current number is higher in value than the sum of this number and currentMax, then the currentMax is updated to the current number's value. Else the sum of such subarray is stored in currentMax
            globalMax = max(globalMax, currentMax); // Update the global max as required.
        }
        return globalMax;
    }
};