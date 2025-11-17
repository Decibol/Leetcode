class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0;
        while (i < nums.size() && nums[i] == 0) ++i;

        cout << i;

        int j = i;
        ++i;
        
        while (i < nums.size()){
            if (nums[i] == 1){
                int length = i - j - 1;

                if (length < k) return false;

                j = i;
            }
            
            ++i;
        }

        return true;
    }
};