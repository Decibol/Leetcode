class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int curr = 1, prev = 0;
        int k = 0;

        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] > nums[i - 1]){
                ++curr;
            }
            else {
                prev = curr;
                curr = 1;
            }

            int minValid = max(curr >> 1, min(prev, curr));
            k = max(k, minValid);
        }

        return k;
    }
};