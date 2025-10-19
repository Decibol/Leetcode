class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<vector<pair<int, int>>> adj(n + 1);
        unordered_set<int> visited;

        for (int i = 0; i < times.size(); ++i){
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        minHeap.push({0, k});
        int time = 0;

        while (!minHeap.empty()){
            auto [weight, node] = minHeap.top();
            minHeap.pop();

            if (visited.count(node)) continue;

            visited.insert(node);
            time = max(time, weight);

            for (auto [w, nei] : adj[node]){
                if (!visited.count(nei)){
                    minHeap.push({weight + w, nei});
                }
            }
        }

        return visited.size() == n ? time : -1;   
    }
};