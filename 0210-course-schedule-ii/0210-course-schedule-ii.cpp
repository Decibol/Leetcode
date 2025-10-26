class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto const& p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        vector<int> order;

        for (int i = 0; i < numCourses; ++i){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (auto const& req : adj[course]){
                --indegree[req];

                if (indegree[req] == 0) q.push(req);
            }
        }

        if (order.size() != numCourses) return {};

        return order;
    }
};