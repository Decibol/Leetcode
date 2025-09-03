class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charMap;

        for (int i = 0; i < s.size(); ++i){
            charMap[s[i]]++;
        }


        for (int i = 0; i < s.size(); ++i){
            if (charMap[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};