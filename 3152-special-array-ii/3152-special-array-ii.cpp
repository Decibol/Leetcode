class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(), 0);

        for (int i = 1; i < nums.size(); ++i){
            prefix[i] = prefix[i - 1];

            if (nums[i - 1] % 2 == nums[i] % 2) ++prefix[i];
        }

        vector<bool> result;

        for (auto const& q : queries){
            int left = q[0];
            int right = q[1];  
            int ans = prefix[right] - prefix[left];
            
            result.push_back(ans == 0);
        }

        return result;
    }
};