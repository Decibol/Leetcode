class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long prod = (long long) nums[n - 1] * nums[n - 2] * 1e5;

        return prod;
    }
};