class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        sort(intervals.begin(), intervals.end()); // sorting so that the smallest interval is in the merged vector that we will make further

        vector<vector<int>> merged; // we store 
        merged.push_back(intervals[0]);

        int n = intervals.size();
        for(int i = 1; i < n; i++){
            vector<int>& last = merged.back(); // get the last interval pushed into merged vector

            if(intervals[i][0] <= last[1]){
                last[1] = max(last[1], intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};