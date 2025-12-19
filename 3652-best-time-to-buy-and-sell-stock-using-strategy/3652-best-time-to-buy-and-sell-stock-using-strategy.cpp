class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long valToSub = 0;
        long long valToAdd = 0;
        long long total = 0;

        for (int i = 0; i < prices.size(); ++i){
            total += prices[i] * strategy[i];
        }

        long long maxTotal = total;
        
        for (int i = 0; i < k; ++i){
            valToSub += (prices[i] * strategy[i]);
        }

        for (int i = k / 2; i < k; ++i){
            valToAdd += prices[i];
        }

        maxTotal = max(maxTotal, total - valToSub + valToAdd);

        int left = 0;
        int mid = k / 2;
        int right = k;

        while (right < prices.size()){
            valToSub += (prices[right] * strategy[right]) - (prices[left] * strategy[left]);
            valToAdd += prices[right] - prices[mid];
            maxTotal = max(maxTotal, total - valToSub + valToAdd); 

            ++left;
            ++mid;
            ++right;
        }

        return maxTotal;
    }
};