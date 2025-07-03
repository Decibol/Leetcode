class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int min_length = numeric_limits<int>::max();
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right){
            sum += nums[right];

            while(sum >= target){
                min_length = min(min_length, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return min_length != numeric_limits<int>::max() ? min_length : 0;
    }
};