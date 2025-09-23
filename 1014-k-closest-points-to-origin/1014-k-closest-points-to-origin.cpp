class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;

        for (auto point : points){
            int x = point[0];
            int y = point[1];

            int distance = x*x + y*y;

            minHeap.push({distance, point});
        }

        vector<vector<int>> result;
        int count = 0;

        while (k > 0){
            auto [distance, point] = minHeap.top();
            minHeap.pop();

            result.push_back(point);
            --k;
        }

        return result;
    }
};