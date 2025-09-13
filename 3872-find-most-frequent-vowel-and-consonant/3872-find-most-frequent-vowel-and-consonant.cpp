class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;

        for (char c : s){
            freq[c]++;
        }

        int maxVowel = 0, maxConsonant = 0;

        for (auto [character, frequency] : freq){
            if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'){
                maxVowel = max(maxVowel, frequency);
            }
            else{
                maxConsonant = max(maxConsonant, frequency);
            }
        }

        return maxVowel + maxConsonant;
    }
};