class Solution {
public:
    int numSub(string s) {
        long long result = 0;
        long long left = 0;   
        long long mod = 1e9 + 7;
        while (left < s.size() && s[left] != '1') ++left;

        long long right = left;

        while (right < s.size()){
            if (s[right] == '1'){
                ++right;
            }
            else {
                long long ones = right - left;
                result += (ones * (ones + 1)) / 2;
                
                while (right < s.size() && s[right] == '0') ++right;

                left = right;
            }
        }

        long long numOnes = right - left;
        result += (numOnes * (numOnes + 1)) / 2;

        result = result % mod;

        return (int)result;
    }
};