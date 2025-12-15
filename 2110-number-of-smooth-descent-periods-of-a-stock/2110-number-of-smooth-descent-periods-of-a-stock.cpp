class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.size() == 1) return 1;

        int size = 1;
        int i = 1;
        long long count = 1;

        while (i < prices.size()){
            if (prices[i] == prices[i - 1] - 1){
                ++size;
            }
            else {
                count += ((long long)size * (long long)(size + 1)) / 2;
                size = 1;
            }

            ++i;
        }

        if (size > 1){
            count += ((long long)size * (long long)(size + 1) / 2) - 1;
        }
        
        return count;
    }
};