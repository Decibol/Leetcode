class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> pair;

        for (int num : nums){
            if (num % 2 == 0){
                pair[num]++;
            }
        }

        int candidate = -1;
        int max_freq = 0;

        for (auto [key, value] : pair){
            if (value >= max_freq){
                if (value == max_freq){
                    candidate = min(candidate, key);
                }
                else{
                    candidate = key;
                }

                max_freq = value;
            }
        }

        return candidate;
    }
};