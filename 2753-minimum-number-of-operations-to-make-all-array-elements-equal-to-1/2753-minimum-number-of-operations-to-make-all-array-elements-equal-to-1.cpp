class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int overall = nums[0];
        int ones = 0;
        if (nums[0] == 1) ++ones;

        for (int i = 1; i < n; ++i){
            overall = gcd(overall, nums[i]);
            if (nums[i] == 1) ++ones;
        }
        

        if (overall > 1) return -1;
        if (ones > 0) return n - ones;

        int minLen = n;

        for (int i = 0; i < n; ++i){
            int cur = nums[i];

            for (int j = i + 1; j < n; ++j){
                cur = gcd(cur, nums[j]);

                if (cur == 1){
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        
        return minLen + n - 2;
    }
};