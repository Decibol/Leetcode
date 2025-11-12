class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums;

        for (int x : nums1){
            for (int y : nums2){
                ++sums[x + y];
            }
        }

        int count = 0;
        
        for (int x : nums3){
            for (int y : nums4){
                int sum = x + y;
                count += sums[-sum];
            }
        }

        return count;
    }
};