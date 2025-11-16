class Solution {
public:
    int countHomogenous(string s) {
        int result = 0;
        int n = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < s.size(); ++i){
            if (i == 0 || s[i] == s[i - 1]){
                ++n;
            }
            else {
                n = 1;
            }

            result = (result + n) % mod;
        }

        return result;
    }
};