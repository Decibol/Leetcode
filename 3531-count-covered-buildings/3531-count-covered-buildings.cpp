class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        if (buildings.size() < 5) return 0;

        int count = 0;
        unordered_map<int, vector<int>> xcor;
        unordered_map<int, vector<int>> ycor;

        sort(buildings.begin(), buildings.end());

        for (auto const& b : buildings){
            xcor[b[0]].push_back(b[1]);
            ycor[b[1]].push_back(b[0]);    
        }

        for (auto const& [y, x] : ycor){
            if (x.size() >= 3){
                for (int i = 1; i < x.size() - 1; ++i){
                    if (y != xcor[x[i]][0] && y != xcor[x[i]][xcor[x[i]].size() - 1]){
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};