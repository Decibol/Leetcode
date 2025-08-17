class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> min, max;
        int left = 0;
        int right;

        for (right = 0; right < nums.size(); ++right){
            while (!min.empty() && nums[right] < min.back()) min.pop_back();
            while (!max.empty() && nums[right] > max.back()) max.pop_back();

            min.push_back(nums[right]);
            max.push_back(nums[right]);

            if (max.front() - min.front() > limit){
                if (max.front() == nums[left]) max.pop_front();
                if (min.front() == nums[left]) min.pop_front();
                ++left;
            }
        }

        return right - left; 
    }
};