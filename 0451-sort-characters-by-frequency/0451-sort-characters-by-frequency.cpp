class Solution {
public:
    string frequencySort(string s) {
        struct cmp {
            bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
                return a.second < b.second;
            }
        };
        
        unordered_map<char, int> freq;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> maxHeap;

        for (int c : s){
            ++freq[c];
        }

        for (auto const& [c, f] : freq){
            maxHeap.push({c, f});
        }

        string result = "";

        while (!maxHeap.empty()){
            auto [character, frequency] = maxHeap.top();
            maxHeap.pop();

            while (frequency > 0){
                result += character;
                --frequency;
            }
        }

        return result;
    }
};