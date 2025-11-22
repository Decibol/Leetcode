class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minOperations = 0;

        for (int x : nums){
            if (x % 3 != 0){
                ++minOperations;
            }
        }   

        return minOperations;
    }
};