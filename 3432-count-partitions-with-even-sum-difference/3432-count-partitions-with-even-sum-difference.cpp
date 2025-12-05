class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> pref(nums.size(), 0);
        pref[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i){
            pref[i] = pref[i - 1] + nums[i];
        }

        int result = 0;
        int total = pref[nums.size() - 1];

        // for (int x : pref) cout << x << ' ' << total - x << endl;

        for (int i = 0; i < pref.size() - 1; ++i){
            int complement = total - pref[i];

            if ((complement - pref[i]) % 2 == 0) ++result; 
        }

        return result;
    }
};