class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (auto x : nums){
            if (!numSet.count(x - 1)){
                int curr = x;
                int count = 1;

                while (true){
                    if (numSet.count(x + 1)){
                        ++count;
                        numSet.erase(x);
                        x += 1;
                    }
                    else {
                        break;
                    }
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};