class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;

        for (int x : nums) total += x;

        int sum = 0;
        int result = 0;

        for (int i = 0; i < nums.size() - 1; ++i){
            sum += nums[i];
            int complement = total - sum;

            if ((complement - sum) % 2 == 0) ++result;
        }

        return result;
    }
};