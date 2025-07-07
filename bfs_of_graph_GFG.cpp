class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        queue<int> q;
        vector<int> bfs;
        vector<bool> visited(V, false);
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for (int neighbor : adj[node]){
                if (visited[neighbor] != true){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return bfs;
    }
};
