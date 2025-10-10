class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> reversedGraph(graph.size());
        vector<int> indegree(graph.size());

        for (int i = 0; i < graph.size(); ++i){
            for (int j = 0; j < graph[i].size(); ++j){
                reversedGraph[graph[i][j]].push_back(i);
            }
        }

        for (int i = 0; i < reversedGraph.size(); ++i){
            for (int j = 0; j < reversedGraph[i].size(); ++j){
                indegree[reversedGraph[i][j]]++;
            }
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < indegree.size(); ++i){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto const& adj : reversedGraph[u]){
                indegree[adj]--;

                if (indegree[adj] == 0) q.push(adj);
            }
        }

        sort(topo.begin(), topo.end());
        
        return topo;
    }
};