class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> numSet;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i){
            if (numSet.find(nums[i]) != numSet.end()){
                result.push_back(nums[i]);
            }

            numSet.insert(nums[i]);
        }

        if (result[0] > result[1]) swap(result[0], result[1]);

        return result;
    }
};