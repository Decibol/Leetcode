class DisjointSet {
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    bool unionBySize(int u, int v){
        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u == root_v) return false;

        if (size[root_u] < size[root_v]){
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        
        for (auto const& e : edges){
            int u = e[0];
            int v = e[1];

            if (!ds.unionBySize(u, v)) return e;
        }

        return {};
    }
};