class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 1 && nums[0] == target) return 1;        
        
        int sum = 0;
        int minLength = INT_MAX;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right){
            sum += nums[right];

            while (sum >= target){
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        if (minLength == INT_MAX) return 0;

        return minLength;
    }
};