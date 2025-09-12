class Solution {
public:
    bool doesAliceWin(string s) {
        int countVowels = 0;

        for (char c : s){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                countVowels++;
            }
        }
        
        if (countVowels == 0) return false;

        return true;
    }
};