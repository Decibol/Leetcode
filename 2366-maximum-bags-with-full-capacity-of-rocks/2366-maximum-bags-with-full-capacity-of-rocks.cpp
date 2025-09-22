class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); ++i){
            capacity[i] = capacity[i] - rocks[i];
        }

        sort(capacity.begin(), capacity.end());

        int i = 0, count = 0;

        while (i < capacity.size() && additionalRocks > 0){
            if (capacity[i] == 0){
                ++count;
            } 
            else {
                if (additionalRocks - capacity[i] >= 0){
                    additionalRocks -= capacity[i];
                    ++count;
                }
                else {
                    break;
                }
            }
            ++i;
        }

        return count;
    }
};