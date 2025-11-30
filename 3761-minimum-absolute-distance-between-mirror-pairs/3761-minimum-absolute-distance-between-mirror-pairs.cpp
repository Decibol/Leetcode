class Solution {
public:
    int reverseNum(int n){
        int num = 0;

        while (n > 0){
            num *= 10;
            num += n % 10;
            n /= 10;
        }

        return num;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int minLength = INT_MAX;

        for (int i = nums.size() - 1; i >= 0; --i){
            int curr = nums[i];
            int rev = reverseNum(curr);
            
            if (mp.count(rev)){
                minLength = min(minLength, mp[rev] - i);
            }

            mp[curr] = i;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};