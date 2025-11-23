class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i){
            prefix[i] = nums[i] + prefix[i - 1];
        }

        unordered_map<int, int> freq;
        int result = 0;

        for (int i = 0; i < nums.size(); ++i){
            if (prefix[i] == k){
                ++result;
            }

            if (freq.count(prefix[i] - k)){
                result += freq[prefix[i] - k];
            }

            ++freq[prefix[i]];
        }

        return result;
    }
};