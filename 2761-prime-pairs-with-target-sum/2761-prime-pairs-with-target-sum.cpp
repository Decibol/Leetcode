class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n + 1, true);
        primes[1] = primes[0] = false;

        for (int i = 2; 1LL * i * i <= n; ++i){
            if (primes[i]){
                for (int j = i * i; j <= n; j += i){
                    primes[j] = false;
                }
            }
        }  
        
        vector<vector<int>> result;

        
        for (int p = 2; p <= n / 2; ++p){
            if (primes[p] && primes[n - p]){
                result.push_back({p, n - p});
            }
        }

        return result;
    }
};