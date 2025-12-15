class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 1;

        int size = 1;
        int i = 1;
        long long count = 1;


        while (i < n){
            if (prices[i] == prices[i - 1] - 1){
                ++size;
            }
            else {
                long long num = ((long long)size * (long long)(size + 1)) / 2;
                count += num;
                size = 1;
            }

            ++i;
        }

        if (size > 1){
            long long num = ((long long)size * (long long)(size + 1) / 2) - 1;
            count += num;
        }
        
        return count;
    }
};