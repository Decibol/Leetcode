class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result = nums;
        k %= n;

        for (int i = 0; i < n; ++i){
            nums[(i + k) % n] = result[i];
        }
    }
};