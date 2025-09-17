class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remainingCapacity(capacity.size(), 0);

        for (int i = 0; i < capacity.size(); ++i){
            remainingCapacity[i] = capacity[i] - rocks[i];
        }

        sort(remainingCapacity.begin(), remainingCapacity.end());

        int count = 0;

        int i = 0;

        while (i < remainingCapacity.size() && additionalRocks > 0){
            if (remainingCapacity[i] == 0){
                ++count;
                ++i;
            }
            else {
                if (additionalRocks - remainingCapacity[i] >= 0){
                    additionalRocks -= remainingCapacity[i];
                    ++count;
                    ++i;
                }
                else {
                    break;
                }
            }
        }

        return count;
    }
};