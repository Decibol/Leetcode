class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max, min;
        int left = 0;
        int right;

        for (right = 0; right < nums.size(); ++right){
            while (!max.empty() && max.back() < nums[right]) max.pop_back();
            while (!min.empty() && min.back() > nums[right]) min.pop_back();

            max.push_back(nums[right]);
            min.push_back(nums[right]);

            if (max.front() - min.front() > limit){
                if (max.front() == nums[left]) max.pop_front();
                if (min.front() == nums[left]) min.pop_front();

                ++left;
            }
        }

        return right - left;
    }
};