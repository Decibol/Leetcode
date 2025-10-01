class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int numEmpty = 0;

        while (numBottles > 0){
            numEmpty += numBottles;
            numBottles = numEmpty / numExchange;
            result += numBottles;
            numEmpty %= numExchange;
        }

        return result;
    }
};