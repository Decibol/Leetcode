class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);

        for (int i = 0; i < nums.size(); ++i){
            freq[nums[i]]++;
        }

        nums.clear();

        int count = 0;

        while (count < freq.size()){
            if (freq[count] == 0){
                count++;
            }
            else{
                nums.push_back(count);
                freq[count]--;
            }
        }
    }
};