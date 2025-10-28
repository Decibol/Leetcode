class Solution {
public:
    void process(vector<int>& nums, int idx, int& valid, int direction){
        vector<int> copy = nums;
        int curr = idx;

        while (curr >= 0 && curr < copy.size()){
            if (copy[curr] == 0){
                curr += direction;
            }
            else if (copy[curr] > 0){
                --copy[curr];

                direction *= -1;

                curr += direction;
            }
        }

        bool check = true;

        for (int num : copy){
            if (num != 0){
                check = false;
                break;
            }
        }

        if (check) ++valid;
    }

    int countValidSelections(vector<int>& nums) {
        int valid = 0;

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                process(nums, i, valid, 1);
                process(nums, i, valid, -1);
            }
        }

        return valid;
    }
};