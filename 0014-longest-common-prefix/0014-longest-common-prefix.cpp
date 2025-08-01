class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string result = "";
        int n = strs.size();

        string s1 = strs[0];
        string s2 = strs[n - 1];

        int left = 0;

        while (left < s1.size() && left < s2.size()){
            if (s1[left] == s2[left]){
                result += s1[left];
                left++;
            }
            else{
                break;
            }
        }

        return result;        
    }
};