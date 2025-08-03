class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> freq;

        for (char c : s){
            freq[c] += 1;
        }

        for (char c : t){
            freq[c] -= 1;
        }

        bool allZero = all_of(freq.begin(), freq.end(), [](auto& pair) {
            return pair.second == 0;
        });

        return allZero;
    }
};