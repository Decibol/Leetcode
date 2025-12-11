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

    void unionBySize(int u, int v){
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

    int findParentCount(int n){
        unordered_set<int> roots;

        for (int i = 0; i < n; ++i){   
            roots.insert(find(i));
        }
        
        return roots.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        int count = 0;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }

        return ds.findParentCount(n);
    }
};