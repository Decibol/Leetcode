class Solution {
public:
    bool isAnagram(string s1, string s2){
        vector<int> c1(26, 0);

        for (char c : s1){
            ++c1[c - 'a'];
        }
        
        for (char c : s2){
            --c1[c - 'a'];
        }

        for (int i = 0; i < c1.size(); ++i){
            if (c1[i] != 0) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i){
            string s = result.back();

            if (!isAnagram(s, words[i])){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};