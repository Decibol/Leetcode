class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> pair;

        for (int i = 0; i < arr.size(); ++i){
            pair[arr[i]]++;
        }

        unordered_set<int> unique;

        for (auto& [key, freq] : pair){
            if (unique.find(freq) != unique.end()){
                return false;
            }

            unique.insert(freq);
        }

        return true;
    }
};