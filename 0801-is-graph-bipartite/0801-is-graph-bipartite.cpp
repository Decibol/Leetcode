class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int& node){
        queue<int> q;
        q.push(node);

        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (auto const& adj : graph[node]){
                if (color[adj] == color[node]){
                    return false;
                }
                else if (color[adj] == 0){
                    color[adj] = -color[node];
                    q.push(adj);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        bool result = true;

        for (int i = 0; i < color.size(); ++i){
            if (color[i] == 0){
                color[i] = 1;
                result = result && bfs(graph, color, i);

                if (!result) return false;
            }
        }

        return true;
    }
};