class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(), [&](const vector<int>& a, const vector<int>& b){
            int distance_a = a[0]*a[0] + a[1]*a[1];
            int distance_b = b[0]*b[0] + b[1]*b[1];

            return distance_a < distance_b;
        });

        vector<vector<int>> result(points.begin(), points.begin() + k);

        return result;
    }
};