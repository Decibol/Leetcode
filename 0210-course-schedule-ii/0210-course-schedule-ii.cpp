class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto const& p : prerequisites){
            adj[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }

        queue<int> q;

        for (int num : indegree){
            if (num == 0) q.push(num);
        }

        vector<int> ordering;

        while (!q.empty()){
            int course = q.front();
            q.pop();
            ordering.push_back(course);

            for (auto const& nei : adj[course]){
                --indegree[nei];

                if (indegree[nei] == 0) q.push(nei);
            }
        }

        if (ordering.size() != numCourses) return {};

        return ordering; 
    }
};