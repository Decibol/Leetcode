class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;
        int minDistance = INT_MAX;

        for (int i = 0; i < nums.size(); ++i){
            freq[nums[i]].push_back(i);
        }
        
        for (auto const& [num, indices] : freq){
            if (indices.size() >= 3){
                for (int i = 0; i < indices.size(); ++i){
                    if (i + 2 < indices.size()){
                        int x = abs(indices[i] - indices[i + 1]) + abs(indices[i + 1] - indices[i + 2]) + abs(indices[i + 2] - indices[i]);
                        minDistance = min(minDistance, x);
                    }
                }
            }
        }

        return minDistance == INT_MAX ? -1 : minDistance;
    }
};