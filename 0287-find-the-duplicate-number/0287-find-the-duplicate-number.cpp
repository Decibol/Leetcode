class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int i = 0; i < nums.size(); ++i){
            if (numSet.find(nums[i]) != numSet.end()){
                return nums[i];
                break;
            }
            
            numSet.insert(nums[i]);
        }

        return 0;
    }
};