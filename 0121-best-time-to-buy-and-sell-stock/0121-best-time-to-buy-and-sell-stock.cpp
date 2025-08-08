class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int minPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i){
            if (minPrice > prices[i]){
                minPrice = prices[i];
            }
            else{
                profit = max(profit, prices[i] - minPrice);
            }
        }

        return profit;
    }
};