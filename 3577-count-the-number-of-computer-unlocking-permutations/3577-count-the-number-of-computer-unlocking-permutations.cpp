class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int MOD = 1e9 + 7;
        int comp = complexity[0];

        for (int i = 1; i < complexity.size(); ++i){
            if (complexity[i] <= comp) return 0;
        }

        long long ans = 1;
        
        for (int i = 1; i < complexity.size(); ++i){
            ans = (ans * i) % MOD;
        }

        return ans % MOD;
    }
};