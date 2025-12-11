class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int num = 1;

        while (true){
            if (numSet.find(num) == numSet.end()) return num;
            ++num;
        }
    }
};