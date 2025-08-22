class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i){
            vector<int>& last = merged.back();

            if (intervals[i][0] <= last[1]){
                last[1] = max(intervals[i][1], last[1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};