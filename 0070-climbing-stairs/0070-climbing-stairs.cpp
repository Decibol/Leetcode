class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        int prev1 = 1;
        int prev2 = 1;

        for (int i = n - 3; i >= 0; --i){
            int temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }

        return prev1 + prev2;
    }
};