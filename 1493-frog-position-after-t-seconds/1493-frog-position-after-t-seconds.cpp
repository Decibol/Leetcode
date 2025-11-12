class Solution {
public:
    double dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int t, int& target){
        if (node != 1 && adj[node].size() == 1 || t == 0){
            return node == target ? 1.0 : 0.0;
        }

        visited[node] = true;
        int unvisited = 0;

        double prob = 0;

        for (auto const& nei : adj[node]){
            if (!visited[nei]){
                prob += dfs(adj, visited, nei, t - 1, target);
            }
        }

        return prob / (adj[node].size() - (node != 1));
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1) return 1.0;

        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);

        for (auto const& p : edges){
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
        }

        return dfs(adj, visited, 1, t, target);
    }
};