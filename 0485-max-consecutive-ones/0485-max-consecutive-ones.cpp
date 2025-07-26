class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int length = 0;

        while (right < nums.size()){
            if (nums[left] == 0) left++;

            if (nums[right] == 1){
                right++;
            }
            else{
                length = max(length, right - left);
                right++;
                left = right;
            }
        }

        length = max(length, right - left);
        return length;
    }
};