class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right){
            if (nums[right] == 0){
                zeroes++;
            }

            while (zeroes > k){
                if (nums[left] == 0){
                    zeroes--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};