class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); ++i){
            capacity[i] = capacity[i] - rocks[i];
        }

        sort(capacity.begin(), capacity.end());

        int count = 0;
        int i = 0;

        while (i < capacity.size() && additionalRocks > 0){
            if (capacity[i] == 0){
                ++count;
                ++i;
            }
            else {
                if (additionalRocks - capacity[i] >= 0){
                    additionalRocks -= capacity[i];
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