class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string s1 = strs[0];
        string s2 = strs[n - 1];

        int i = 0;
        string result = "";

        while (i < s1.size() && i < s2.size()){
            if (s1[i] == s2[i]){
                result += s1[i];
                i++;
            }
            else{
                break;
            }
        }

        return result;
    }
};