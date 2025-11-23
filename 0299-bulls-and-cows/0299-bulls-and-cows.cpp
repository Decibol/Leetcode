class Solution {
public:
    string getHint(string secret, string guess) {
        int cows = 0;
        int bulls = 0; 
        unordered_map<char, int> freq;

        for (int i = 0; i < secret.size(); ++i){
            if (secret[i] == guess[i]){ 
                ++bulls;
                secret[i] = guess[i] = '#';
            }
            else {
                ++freq[secret[i]];
            }
        }

        for (int i = 0; i < guess.size(); ++i){
            if (freq.count(guess[i])){
                ++cows;
                --freq[guess[i]];

                if (freq[guess[i]] == 0) freq.erase(guess[i]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};