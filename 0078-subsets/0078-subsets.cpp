class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        function<void(int)> dfs = [&](int i) {
            if (i >= nums.size()) {
                result.push_back(current);
                return;
            }

            current.push_back(nums[i]);
            dfs(i + 1);

            current.pop_back();
            dfs(i + 1);
        };

        dfs(0);
        return result;
    }
};
