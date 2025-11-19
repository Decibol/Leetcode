class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;

        while (i < m && j < n){
            if (nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                ++i;
            }
            else {
                nums.push_back(nums2[j]);
                ++j;
            }
        }

        if (j < n) nums.insert(nums.end(), nums2.begin() + j, nums2.end());
        if (i < m) nums.insert(nums.end(), nums1.begin() + i, nums1.end());
        
        int left = 0;
        int right = nums.size() - 1;
        double median = 0.0;

        if (nums.size() % 2 == 1){
            median = (double)nums[nums.size() / 2];
        }
        else {
            median = (double)(nums[nums.size() / 2] + nums[(nums.size() / 2) - 1]) / 2;
        }

        return median;
    }
};