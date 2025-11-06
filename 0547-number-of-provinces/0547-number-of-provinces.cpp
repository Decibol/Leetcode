class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& isConnected, vector<bool>& visited){
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            visited[c] = true;

            for (int j = 0; j < isConnected[c].size(); ++j){
                if (isConnected[c][j] == 1 && !visited[j]){
                    q.push({c, j});
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (isConnected[i][j] == 1 && !visited[j]){
                    bfs(i, j, isConnected, visited);
                    ++count;
                }
            }
        }

        return count;
    }   
};