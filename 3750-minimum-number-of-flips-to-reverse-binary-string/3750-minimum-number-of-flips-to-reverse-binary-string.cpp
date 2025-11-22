class Solution {
public:
    string intToBin(int n){
        string s = "";

        while (n > 0){
            char c = '0' + (n % 2);
            n /= 2;
            s += c;
        }

        return s;
    }
    
    int minimumFlips(int n) {
        string s1 = intToBin(n);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int minOperations = 0;
        
        for (int i = 0; i < s1.size(); ++i){
            if (s1[i] != s2[i]){
                ++minOperations;
            }
        }

        return minOperations;
    }
};