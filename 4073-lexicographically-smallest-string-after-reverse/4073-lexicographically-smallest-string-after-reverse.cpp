class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        if (n == 1) return s;
        
        char minChar = *min_element(s.begin(), s.end());
        string best = "~";

        for (int i = 0; i < n; ++i){
            if (s[i] == minChar){
                string temp = s;
                reverse(temp.begin(), temp.begin() + i + 1);
                best = min(best, temp);
            }
        }

        for (int i = 1; i <= n; ++i){
            string temp = s;
            reverse(temp.end() - i, temp.end());
            best = min(best, temp);
        }

        return best;
    }
};