class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        int current = nums[0] + 1;
        vector<int> missing;

        while (i < nums.size()){
            if (current != nums[i]){
                missing.push_back(current);        
            }
            else {
                ++i;
            }

            ++current;
        }

        return missing;
    }
};