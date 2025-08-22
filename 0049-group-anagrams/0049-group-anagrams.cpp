class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> answer;

        for (string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            anagrams[key].push_back(str);
        }

        for (const auto& pair : anagrams){
            answer.push_back(pair.second);
        }

        return answer;
    }
};