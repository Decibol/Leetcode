class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate, missing;

        for (int num : nums){
            int idx = abs(num) - 1;
            
            if (nums[idx] < 0){
                duplicate = abs(num);
            }
            else{
                nums[idx] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0){
                missing = i + 1;
            }
        }

        return {duplicate, missing};
    }
};