class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> merged;
        merged.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i){
            vector<int>& last = merged.back();

            if (nums[i][0] <= last[1]){
                last[1] = max(last[1], nums[i][1]);
            }
            else {
                merged.push_back(nums[i]);
            }
        }

        int points = 0;

        for (int i = 0; i < merged.size(); ++i){
            points += merged[i][1] - merged[i][0] + 1;
        }

        return points;
    }
};