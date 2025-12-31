class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for (auto const& time : times){
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adj[u].push_back({t, v});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        
        while (!minHeap.empty()){
            auto [time, node] = minHeap.top();
            minHeap.pop();

            if (time > dist[node]) continue;

            for (auto const& nei : adj[node]){
                int t = nei.first;
                int v = nei.second;

                if (time + t < dist[v]){
                    dist[v] = time + t;
                    minHeap.push({dist[v], v});
                }
            }
        }
        
        int maxTime = INT_MIN;

        for (int i = 1; i <= n; ++i){
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
