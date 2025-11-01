class Solution {
public:
    bool bfs(int& node, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(node);

        while (!q.empty()){
            int u = q.front();
            q.pop();

            for (auto const& nei : graph[u]){
                if (color[nei] == color[u]){
                    return false;
                }
                else if (color[nei] == 0){
                    color[nei] = -color[u];
                    q.push(nei);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);

        for (int i = 0; i < graph.size(); ++i){
            if (color[i] == 0){
                color[i] = 1;
                if (!bfs(i, graph, color)) return false;
            }
        }

        return true;
    }
};