class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pair;
        
        for (int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];
            if (pair.find(complement) != pair.end()){
                return {i, pair[complement]};
            }
            pair[nums[i]] = i;
        }
        return {};
    }
};