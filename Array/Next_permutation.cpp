class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2; // We want to initialize i from the 2nd last element.

        while(i>=0 && nums[i] >= nums[i+1]){ // First we find the first element from the right where the logic of nums[i] >= nums[i+1] does not hold true
            i--;
        }

        if(i >= 0){
            int j = n - 1; // Initialize j from the last element.
            while(nums[j] <= nums[i]){ // We find the next larger element's index
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};