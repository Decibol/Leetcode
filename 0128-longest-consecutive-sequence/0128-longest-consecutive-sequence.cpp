class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (auto x : nums){
            if (!numSet.count(x - 1)){
                int count = 1;

                while (numSet.count(x + 1)){
                    numSet.erase(x);
                    ++x;
                    ++count;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};