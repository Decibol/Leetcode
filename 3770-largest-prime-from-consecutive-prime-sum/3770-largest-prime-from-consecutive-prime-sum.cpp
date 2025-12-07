class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int i = 2; i * i <= n; ++i){
            if (isPrime[i]){
                for (int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }

        int sum = 0;
        int result = 0;
        
        for (int i = 2; i <= n && sum <= n; ++i){
            if (isPrime[i]){
                sum += i;

                if (sum <= n && isPrime[sum]) result = sum; 
            }
        }

        return result;
    }
};