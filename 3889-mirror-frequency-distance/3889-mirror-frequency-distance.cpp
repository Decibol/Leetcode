class Solution {
public:
    int mirrorFrequency(string s) {
        if (s.size() == 1) return 1;

        int sum = 0;

        vector<int> charFreq(26, 0);
        vector<int> numFreq(10, 0);

        for (char c : s){
            if (isalpha(c)) ++charFreq[c - 'a'];
            else ++numFreq[c - '0'];
        }

        for (int i = 0; i < 26; ++i){
            sum += abs(charFreq[i] - charFreq[25 - i]);
            charFreq[i] = 0;
            charFreq[25 - i] = 0; 
        }

        for (int i = 0; i < 10; ++i){
            sum += abs(numFreq[i] - numFreq[9 - i]);
            numFreq[i] = 0;
            numFreq[9 - i] = 0;
        }

        return sum;
    }
};