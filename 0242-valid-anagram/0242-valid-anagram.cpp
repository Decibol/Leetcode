class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> result(26, 0);

        for (char c : t) result[c - 'a']++;
        for (char c : s) result[c - 'a']--;

        for (int num : result){
            if (num != 0) return false;
        }

        return true;
    }
};