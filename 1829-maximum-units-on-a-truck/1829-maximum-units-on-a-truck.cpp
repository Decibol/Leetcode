class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });

        int maximum = 0;

        for (int i = 0; i < boxTypes.size(); ++i){
            int putInTruck = min(boxTypes[i][0], truckSize);
            truckSize -= putInTruck;
            maximum += putInTruck * boxTypes[i][1];
        }

        return maximum;
    }
};