class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneSet(bank.begin(), bank.end());
        geneSet.erase(startGene);
        
        if (!geneSet.count(endGene)) return -1;
        if (startGene == endGene) return 1;
        if (bank.empty()) return -1;
        
        vector<char> genes = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        int count = 0;

        while (!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                string gene = q.front();
                q.pop();
                string copy = gene;

                for (int j = 0; j < copy.size(); ++j){
                    char original = copy[j];

                    for (char c : genes){
                        if (c == original) continue;
                        copy[j] = c;

                        if (copy == endGene) return count + 1;

                        if (geneSet.count(copy)){
                            q.push(copy);
                            geneSet.erase(copy);
                        }
                    }
                    
                    copy[j] = original;
                }
            }

            ++count;
        }

        return -1;        
    }
};