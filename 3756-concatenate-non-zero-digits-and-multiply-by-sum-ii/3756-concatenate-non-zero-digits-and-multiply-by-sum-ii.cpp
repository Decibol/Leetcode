class Solution {
public:
    long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<long long> powers(n + 1);
        powers[0] = 1;
        for (int i = 1; i <= n; ++i) {
            powers[i] = (powers[i - 1] * 10) % MOD;
        }

        vector<long long> prefixVal(n + 1, 0);
        vector<long long> prefixSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);

        long long currentNum = 0;
        long long currentSum = 0;
        int currentNonZeros = 0;

        for (int i = 0; i < n; ++i){
            int digit = s[i] - '0';
            
            if (s[i] != '0') {
                currentNum = (currentNum * 10) % MOD;
                currentNum = (currentNum + digit) % MOD;
                currentNonZeros++;
            }
            
            currentSum += digit;

            prefixVal[i + 1] = currentNum;
            prefixSum[i + 1] = currentSum;
            nonZeroCount[i + 1] = currentNonZeros;
        }

        vector<int> result;
        for (auto& q : queries) {
            int L = q[0]; 
            int R = q[1]; 

            long long rangeSum = prefixSum[R + 1] - prefixSum[L];

            long long fullVal = prefixVal[R + 1];
            long long prevVal = prefixVal[L];
            int countInBetween = nonZeroCount[R + 1] - nonZeroCount[L];
            
            long long toSubtract = (prevVal * powers[countInBetween]) % MOD;
            long long rangeNum = (fullVal - toSubtract) % MOD;
            
            if (rangeNum < 0) rangeNum += MOD;

            long long ans = (rangeNum * rangeSum) % MOD;
            result.push_back((int)ans);
        }

        return result;
    }
};