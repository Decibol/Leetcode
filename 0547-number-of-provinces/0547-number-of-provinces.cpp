class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        if (visited[node]) return;

        visited[node] = true;

        for (int i = 0; i < isConnected.size(); ++i){
            if (isConnected[node][i] == 1 && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        if (n == 0) return 0;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i){
            if (!visited[i]){
                dfs(i, isConnected, visited);
                ++provinces;
            }
        }

        return provinces;    
    }
};