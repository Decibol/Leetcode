class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int result = 0;

        while (nums.size() != 1){
            vector<int> current;

            for (int i = 1; i < nums.size(); ++i){
                int sum = (nums[i] + nums[i - 1]) % 10;
                current.push_back(sum);
            }

            nums = current;
        }

        return nums[0];
    }
};