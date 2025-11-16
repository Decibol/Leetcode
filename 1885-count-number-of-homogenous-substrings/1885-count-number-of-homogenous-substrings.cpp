class Solution {
public:
    int countHomogenous(string s) {
        unordered_map<string, long long> freq;
        long long result = 0;
        long long mod = 1e9 + 7;
        string homo = "";

        for (int i = 0; i < s.size(); ++i){
            if (i == 0 || homo.back() == s[i]){
                homo += s[i];
            }
            else {
                freq[homo]++;
                homo = s[i];
            }
        }

        freq[homo]++;

        for (auto [str, fre] : freq){
            long long n = str.size();
            long long sum = fre * ((n * (n + 1)) / 2);
            result += sum;
        }

        result %= mod;
        
        return (int)result;        
    }
};