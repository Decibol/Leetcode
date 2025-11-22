class Solution {
public:    
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long totalSum = (long long)n * (n + 1) / 2;
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0) return {};

        long long negSum = (totalSum - target) / 2;
        vector<int> chosen(n + 1, 0);
        
        for (int i = n; i >= 1 && negSum > 0; --i){
            if (i <= negSum){
                chosen[i] = 1;
                negSum -= i;
            }
        }

        vector<int> result;
        
        for (int i = 1; i <=n; ++i){
            if (chosen[i] == 1){
                result.push_back(-i);
            }
            else {
                result.push_back(i);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};