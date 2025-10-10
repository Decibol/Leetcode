class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        unordered_set<int> visited;

        for (auto const& pair : prerequisites){
            adj[pair[0]].push_back(pair[1]);
        }

        function<bool(int)> dfs = [&](int course){
            if (adj[course].empty()) return true;

            if (visited.count(course)) return false;
            visited.insert(course);

            for (int& x : adj[course]){
                if (!dfs(x)) return false;
            }

            adj[course].clear();
            
            return true;
        };

        for (int i = 0; i < numCourses; ++i){
            if (!dfs(i)) return false;
        }

        return true;
    }
};