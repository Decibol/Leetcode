class Solution {
public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0) return 0;

        vector<char> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            ++provinces;

            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()){
                int cur = q.front();
                q.pop();

                for (int j = 0; j < n; ++j){
                    if (isConnected[cur][j] && !visited[j]){
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }

        return provinces;
    }
};
