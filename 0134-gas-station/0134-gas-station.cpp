class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas = 0;

        for (int i = 0; i < gas.size(); ++i){
            totalCost += cost[i];
            totalGas += gas[i];
        }

        if (totalCost > totalGas) return -1;

        int tank = 0;
        int startIdx = 0;

        for (int i = 0; i < gas.size(); ++i){
            tank += gas[i];

            if (tank - cost[i] < 0){
                tank = 0;
                startIdx = i + 1;
            }
            else {
                tank -= cost[i];
            }
        }

        return startIdx;
    }
};