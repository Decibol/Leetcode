class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> need;

        for (auto const& f : friendships){
            int u = f[0] - 1;
            int v = f[1] - 1;
            bool canComm = false;

            for (auto const& i : languages[u]){
                for (auto const& j : languages[v]){
                    if (i == j){
                        canComm = true;
                        break;
                    }
                }
            }

            if (!canComm){
                need.insert(u);
                need.insert(v);
            }
        }

        int res = INT_MAX;

        for (int i = 1; i <= n; ++i){
            int canLearn = 0;

            for (auto const& x : need){
                bool knows = false;

                for (auto const& y : languages[x]){
                    if (i == y){
                        knows = true;
                        break;
                    }
                }

                if (!knows) ++canLearn;
            }

            res = min(res, canLearn);
        }

        return res; 
    }
};