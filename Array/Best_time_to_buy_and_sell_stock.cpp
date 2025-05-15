class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Initiate the first element as the current minimum price. Then iterate through the
        vector to check if at any other index, the price is lower. Then, we try to find the price
        which is the highest to the RIGHT side of that index, in which case we get the max profit.  
        */
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else{
                profit = max(profit, prices[i] - minPrice);
            }
        }
        return profit;
    }
};