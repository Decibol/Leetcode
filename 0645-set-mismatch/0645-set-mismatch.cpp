class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; ++i){
            freq[nums[i]] += 1;
        }
        int duplicate;
        int missing;

        for (int i = 1; i < freq.size(); ++i){
            if (freq[i] == 2) duplicate = i;
            if (freq[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};