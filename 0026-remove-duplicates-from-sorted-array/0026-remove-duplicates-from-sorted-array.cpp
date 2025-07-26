class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;

        int i = 1;

        while (i < nums.size()){
            if (nums[i] == nums[i - 1]){
                nums.erase(nums.begin() + i);
            }
            else{
                i++;
            }
        }

        return nums.size();
    }
};