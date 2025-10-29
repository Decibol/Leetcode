class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        if (visited[node]) return;

        visited[node] = true;

        for (int connection : adj[node]){
            dfs(connection, adj, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }

        vector<bool> visited(n, false); 
        int count = 0;

        for (int i = 0; i < adj.size(); ++i){
            if (!visited[i]){
                dfs(i, adj, visited);
                ++count;
            }
        }

        return count;
    }
};