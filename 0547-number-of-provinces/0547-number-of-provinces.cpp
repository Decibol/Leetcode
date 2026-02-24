class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        size.resize(n, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node){
        if (node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v){
        int x = find(u);
        int y = find(v);

        if (x == y) return;

        if (size[y] > size[x]){
            parent[x] = y;
            size[y] += size[x];
        }
        else {
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU ds(isConnected.size());

        for (int i = 0; i < isConnected.size(); ++i){
            for (int j = 0; j < isConnected.size(); ++j){
                if (i != j && isConnected[i][j]){
                    ds.unite(i, j);
                }
            }
        }

        unordered_set<int> ultimateParent;

        for (int i = 0; i < ds.parent.size(); ++i){
            ultimateParent.insert(ds.find(i));
        }

        return ultimateParent.size();
    }
};