class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> freq;

        for (char c : s) freq[c]++;
        for (char c : t) freq[c]--;

        bool allZero = all_of(freq.begin(), freq.end(), [](const auto& pair){
            return pair.second == 0;
        });

        return allZero;
    }
};