class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int count = 0;

        while (right < nums.size() - 1){
            int n = right;
            
            for (int i = left; i <= n; ++i){
                right = max(right, i + nums[i]);
            }

            left = n;
            count++;
        }

        return count;
    }
};