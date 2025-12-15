class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.size() == 1) return 1;

        long long size = 1;
        long long count = 1;

        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] == prices[i - 1] - 1){
                ++size;
            }
            else {
                count += (size * (size + 1)) / 2;
                size = 1;
            }
        }

        if (size > 1){
            count += (size * (size + 1) / 2) - 1;
        }
        
        return count;
    }
};