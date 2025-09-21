class Solution {
public:
    bool mergeTriplets(const vector<vector<int>>& triplets, const vector<int>& target) {
        vector<int> cur = {0,0,0};
        for (const auto &t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                cur[0] = max(cur[0], t[0]);
                cur[1] = max(cur[1], t[1]);
                cur[2] = max(cur[2], t[2]);
            }
        }
        
        return cur == target;
    }
};
