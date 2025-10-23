class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.size() <= 2) return false;

        while (s.size() > 2){
            int left = 0;
            int right = 1;

            string result = "";

            while (right < s.size()){
                int a = s[left] - '0';
                int b = s[right] - '0';

                int new_digit = (a + b) % 10;

                result += to_string(new_digit);

                ++left;
                ++right;
            }

            s = result;
        }

        return s.size() == 2 && s[0] == s[1];
    }
};