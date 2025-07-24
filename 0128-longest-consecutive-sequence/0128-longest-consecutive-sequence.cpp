class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        set<int> order(nums.begin(), nums.end());

        int longest = 1;
        int count = 1;

        vector<int> orderedVec(order.begin(), order.end());

        if (orderedVec.size() == 0) return 0;

        for (int i = 1; i < orderedVec.size(); ++i) {
            if (orderedVec[i] == orderedVec[i - 1] + 1) {
                count++;

            } else {
                count = 1;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};