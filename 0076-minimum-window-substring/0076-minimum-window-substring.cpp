class Solution {
public:
    string minWindow(string s, string t) {
        if (s == t) return s;
        int m = s.size();
        int n = t.size();
        if (m < n) return "";
        
        vector<int> need(128, 0);
        
        for (char c : t) ++need[c];

        int required = 0;
        for (int x : need) if (x > 0) ++required;

        vector<int> window(128, 0);
        int formed = 0;
        int bestLeft = 0;
        int minLength = INT_MAX;
        int left = 0, right = 0;

        while (right < m){
            ++window[s[right]];

            if (need[s[right]] > 0 && need[s[right]] == window[s[right]]){
                ++formed;
            }

            while (left <= right && formed == required){
                int length = right - left + 1;

                if (length < minLength){
                    minLength = length;
                    bestLeft = left;
                }

                --window[s[left]];

                if (need[s[left]] > 0 && need[s[left]] > window[s[left]]){
                    --formed;
                }

                ++left;
            }

            ++right;
        }

        return minLength == INT_MAX ? "" : s.substr(bestLeft, minLength);
    }
};