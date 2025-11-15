class Solution {
public:
    bool canAllocate(vector<int>& candies, long long& mid, long long k){
        int i = 0;

        while (i < candies.size() && k > 0){
            int num = candies[i];
            int piles = num / mid;

            k -= piles;

            ++i;
        }

        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (int num : candies) sum += num;

        if (sum < k) return 0;

        long long left = 1;
        long long right = sum / k;
        long long result = 0;

        while (left <= right){
            long long mid = (left + right) / 2;

            if (canAllocate(candies, mid, k)){
                result = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return (int)result;
    }
};