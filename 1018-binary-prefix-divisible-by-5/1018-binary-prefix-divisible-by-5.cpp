class Solution {
public:    
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        vector<bool> res(nums.size(), false);

        for (int i = 0; i < nums.size(); ++i){
            num = (2 * num + nums[i]) % 5;

            if (num == 0){
                res[i] = true;
            } 
        }
        
        return res;
    }
};