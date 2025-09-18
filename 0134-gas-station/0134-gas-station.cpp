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

        int startIdx = 0;
        int tank = 0;

        for (int i = 0; i < gas.size(); ++i){
            tank += gas[i];

            if (tank - cost[i] < 0){
                startIdx = i + 1;
                tank = 0;
            }   
            else {
                tank -= cost[i];
            }
        }

        return startIdx;
    }
};