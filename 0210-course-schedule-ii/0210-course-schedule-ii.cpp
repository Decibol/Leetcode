class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto const& pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
        }

        for (int i = 0; i < adj.size(); ++i){
            for (int j = 0; j < adj[i].size(); ++j){
                indegree[adj[i][j]]++;
            }
        }

        for (auto num : indegree) cout << num << ' ';

        vector<int> topo;
        queue<int> q;

        for (int i = 0; i < indegree.size(); ++i){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int course = q.front();
            q.pop();
            topo.push_back(course);

            for (auto const& pre : adj[course]){
                indegree[pre]--;
                
                if (indegree[pre] == 0) q.push(pre);
            }
        }
    
        if (topo.size() != numCourses) return {};

        return topo;
    }
};