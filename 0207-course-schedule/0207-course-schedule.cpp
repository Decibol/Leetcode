class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto const& pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
            indegree[pair[0]]++;
        }

        vector<int> topo;
        queue<int> q;
    
        for (int i = 0; i < indegree.size(); ++i){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int course = q.front();
            q.pop();
            topo.push_back(course);

            for (auto const& nextCourse : adj[course]){
                indegree[nextCourse]--;
                
                if (indegree[nextCourse] == 0) q.push(nextCourse);
            }
        }

        if (topo.size() != numCourses) return false;

        return true;
    }
};