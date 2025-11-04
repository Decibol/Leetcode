class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> result;

        int left = 0;

        for (int right = 0; right < nums.size(); ++right){
            ++freq[nums[right]];

            if (right >= k - 1){
                for (auto [element, frequency] : freq){
                    minHeap.push({frequency, element});

                    if (minHeap.size() > x){
                        minHeap.pop();
                    }
                }
                
                int sum = 0;

                while (!minHeap.empty()){
                    auto [fre, ele] = minHeap.top();
                    minHeap.pop();

                    sum += fre * ele;
                }

                result.push_back(sum);
                --freq[nums[left]];
                ++left;
            }
        }

        return result;
    }
};