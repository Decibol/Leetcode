class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        long long count = 0;

        unordered_map<int, int> suff;
        unordered_map<int, int> pref;

        for (auto x : nums) ++suff[x];

        for (auto x : nums){
            --suff[x];
            count += (long long)suff[2 * x] * pref[2 * x];
            ++pref[x];
        }

        return count % MOD;
    }
};