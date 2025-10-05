class Solution {
public:
    void backtrack(int start, string& digits, unordered_map<char, string>& charMap, string current, vector<string>& result){
        if (start == digits.size()){
            result.push_back(current);
            return;
        }

        string s = charMap[digits[start]];

        for (char c : s){
            backtrack(start + 1, digits, charMap, current + c, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> charMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;

        backtrack(0, digits, charMap, "", result);

        return result;    
    }
};