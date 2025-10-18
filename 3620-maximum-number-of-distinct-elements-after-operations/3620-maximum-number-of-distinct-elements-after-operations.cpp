class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int result = 0;
        int current = INT_MIN;

        sort(nums.begin(), nums.end());

        for (int num : nums){
            int target = max(current + 1, num - k);

            if (target <= num + k){
                current = target;
                ++result;
            }
        }

        return result;
    }
};