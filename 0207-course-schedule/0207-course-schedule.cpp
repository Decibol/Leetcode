class Solution {
public:
    unordered_set<int> visited;

    bool dfs(int course, unordered_map<int, vector<int>>& adj){
        if (adj[course].empty()){
            return true;
        }

        if (visited.count(course)){
            return false;
        }

        visited.insert(course);

        for (int p : adj[course]){
            if (!dfs(p, adj)) return false;
        }

        adj[course].clear();

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for (auto const& pair : prerequisites){
            adj[pair[0]].push_back(pair[1]);
        }

        for (int i = 0; i < numCourses; ++i){
            if (!dfs(i, adj)) return false;
        }

        return true;
    }
};