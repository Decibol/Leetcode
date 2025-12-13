class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v){
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) return;

        if (size[root_u] < size[root_v]){
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n == 1 || connections.size() < n - 1) return -1;
        DisjointSet ds(n);

        for (auto con : connections){
            ds.unite(con[0], con[1]);
        }

        int components = 0;

        for (int i = 0; i < n; ++i){
            if (ds.find(i) == i) ++components;
        }

        return components - 1;
    }
};