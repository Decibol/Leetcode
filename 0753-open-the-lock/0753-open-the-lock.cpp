class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        string init = "0000";
        int turns = 0;

        if (init == target) return 0;
        if (deads.count(init)) return -1;
        
        queue<string> q;
        q.push(init);
        visited.insert(init);

        while (!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                string combo = q.front();
                q.pop();

                if (combo == target) return turns;

                for (int j = 0; j < combo.size(); ++j){
                    char original = combo[j];

                    combo[j] = (original == '9' ? '0' : original + 1);

                    if (!deads.count(combo) && !visited.count(combo)){
                        q.push(combo);
                        visited.insert(combo);
                    }

                    combo[j] = (original == '0' ? '9' : original - 1);

                    if (!deads.count(combo) && !visited.count(combo)){
                        q.push(combo);
                        visited.insert(combo);
                    }

                    combo[j] = original;
                }
            }

            ++turns;
        }

        return -1;
    }
};