class Solution {
public:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color){
        color[node] = c;

        for (auto const& neigh : graph[node]){
            if (color[neigh] == c){
                return false;
            }
            else if (color[neigh] == 0){
                if (!dfs(neigh, -c, graph, color)) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        
        for (int i = 0; i < graph.size(); ++i){
            if (color[i] == 0){
                if (!dfs(i, 1, graph, color)) return false;
            }
        }

        return true;
    }
};