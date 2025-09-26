class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> freq;

        for (int x : nums){
            ++freq[x];
        }

        for (auto const& [num, frequency] : freq){
            minHeap.push({frequency, num});

            if (minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> result;

        while (!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};