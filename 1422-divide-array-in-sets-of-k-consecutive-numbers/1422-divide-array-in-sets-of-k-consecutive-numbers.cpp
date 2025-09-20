class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> freq;

        for (int x : nums) freq[x]++;

        while (!freq.empty()){
            int start = freq.begin()->first;
            int count = freq.begin()->second;

            for (int i = 0; i < k; ++i){
                int num = start + i;
                if (freq.find(num) == freq.end()) return false;

                freq[num] -= count;

                if (freq[num] < 0) return false;
                if (freq[num] == 0) freq.erase(num);
            }
        }

        return true;
    }
};