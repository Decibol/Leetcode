class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words;
        unordered_map<string, int> freq;

        int left = 0;

        for (int right = 0; right < text.size() + 1; ++right){
            if (text[right] == ' ' || right == text.size()){
                string str = text.substr(left, right - left);
                freq[str]++;

                words.push_back(str);

                left = right + 1;
            }
        }

        int count = words.size();

        for (int i = 0; i < brokenLetters.size(); ++i){
            for (int j = 0; j < words.size(); ++j){
                if (words[j].find(brokenLetters[i]) != string::npos && freq[words[j]] > 0){
                    freq[words[j]]--;
                    count--;
                }
            }
        }

        return count;
    }
};