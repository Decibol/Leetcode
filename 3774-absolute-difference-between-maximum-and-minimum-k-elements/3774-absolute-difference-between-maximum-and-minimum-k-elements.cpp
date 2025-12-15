class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minSum = 0;
        int maxSum = 0;

        for (int i = 0, j = nums.size() - 1; i < k; ++i, --j){
            minSum += nums[i];
            maxSum += nums[j];
        }

        return maxSum - minSum;
    }
};