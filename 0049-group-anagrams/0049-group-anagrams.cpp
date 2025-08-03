class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> anagramGroups;
        
        for (string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            anagramGroups[key].push_back(s);
        }

        for (const auto& pair : anagramGroups){
            answer.push_back(pair.second);
        }

        return answer;        
    }
};