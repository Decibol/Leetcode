class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < n; ++i){
            if (freq.find(nums[i]) != freq.end()){
                freq[nums[i]] += 1;
            }
            else{
                freq[nums[i]] = 1;
            }
        }

        vector<int> ans;

        for (auto [element, count] : freq){
            if (count > n / 3){
                ans.push_back(element);
            }
        }
        
        return ans;
    }
};