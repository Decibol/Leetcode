class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;

        string result = s.substr(0, 1);
        int maxLength = 1;

        for (int i = 1; i < s.size(); ++i){
            int left = i - 1;
            int right = i + 1;

            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    if (maxLength < right - left + 1){
                        maxLength = right - left + 1;
                        result = s.substr(left, maxLength);
                    }

                    ++right;
                    --left;
                }
                else {
                    break;
                }
            }

            left = i - 1;
            right = i;

            while (left >= 0 && right < s.size()){
                if (s[left] == s[right]){
                    if (maxLength < right - left + 1){
                        maxLength = right - left + 1;
                        result = s.substr(left, maxLength);
                    }

                    ++right;
                    --left;
                }
                else {
                    break;
                }
            }
        }

        return result;
    }
};