class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> pair;

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] % 2 == 0){
                pair[nums[i]]++;
            }
        }

        int most_freq = 0;
        int candidate = -1;

        for (auto [key, value] : pair){
            if (value >= most_freq){

                if (value == most_freq){
                    candidate = min(candidate, key);
                }

                else{
                    candidate = key;
                }

                most_freq = value;
            }
        }

        return candidate == -1 ? -1 : candidate;
    }
};