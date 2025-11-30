class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums) total += x;

        if (total % p == 0) return 0;
        
        int rem = total % p;
        long long pref = 0;
        unordered_map<long long, int> mp;
        int ans = nums.size();
        mp[0] = -1;

        for (int i = 0; i < nums.size(); ++i){
            pref = (pref + nums[i]) % p;
            int need = (pref - rem + p) % p;

            if (mp.count(need)){
                ans = min(ans, i - mp[need]);
            }

            mp[pref] = i;
        }

        return ans == nums.size() ? - 1 : ans; 
    }
};