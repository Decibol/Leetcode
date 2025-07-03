class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maximum = 0;
        int right = 0;
        int zeroes = 0;
        while (right < nums.size()){
            if (nums[right] == 0){
                zeroes++;
            }

            while (zeroes > k){
                if (nums[left] == 0){
                    zeroes -= 1;
                }
                left++;
            }
            if (right - left + 1 > maximum){
                maximum = right - left + 1;
            }
            right += 1;
        }
        return maximum;
    }
};