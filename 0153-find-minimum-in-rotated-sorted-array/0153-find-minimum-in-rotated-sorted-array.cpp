class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if (n == 1 || nums[0] < nums[n - 1]) return nums[0];

        int left = 0, right = n - 1;

        while (left <= right){
            int mid = (left + right) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1]) return nums[mid];
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) return nums[mid + 1];

            if (nums[left] <= nums[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};