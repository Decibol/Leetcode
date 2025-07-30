class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        if (s.length() == 1) return s;
        
        string result = s.substr(0, 1);
        int max_length = 1;

        for (int i = 1; i < s.size(); ++i){
            int left = i - 1;
            int right = i + 1;

            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    if (max_length < right - left + 1){
                        max_length = right - left + 1;
                        result = s.substr(left, max_length);
                    }
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }

            left = i - 1;
            right = i;

            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    if (max_length < right - left + 1){
                        max_length = right - left + 1;
                        result = s.substr(left, right - left + 1);
                    }
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
        }

        return result;
    }
};