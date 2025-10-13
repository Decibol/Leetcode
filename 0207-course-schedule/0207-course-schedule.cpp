class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);

        for (auto const& p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }

        queue<int> q;
        int count = 0;

        for (int i = 0; i < indegrees.size(); ++i){
            if (indegrees[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int course = q.front();
            q.pop();
            ++count;

            for (auto const& pre : adj[course]){
                --indegrees[pre];
                
                if (indegrees[pre] == 0) q.push(pre);
            }
        }

        return count == numCourses;
    }
};