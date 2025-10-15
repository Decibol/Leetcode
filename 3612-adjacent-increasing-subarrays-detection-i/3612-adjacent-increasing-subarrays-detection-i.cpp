class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int curr = 1, prev = 0;

        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] > nums[i - 1]){
                ++curr;
                
                if (curr >= 2 * k) return true;
            }
            else {
                if (curr >= k && prev >= k) return true;
                
                prev = curr;
                curr = 1;
            }
        }

        return curr >= k && prev >= k;
    }
};