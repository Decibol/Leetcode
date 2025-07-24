class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet){
            if (numSet.find(num - 1) == numSet.end()){
                int count = 1;

                while (numSet.find(num + 1) != numSet.end()){
                    num++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};