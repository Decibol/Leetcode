class Solution {
public:
    bool canFinish(vector<int>& piles, int& h, int& k){
        long long hours = 0;

        for (const int& pile : piles){
            hours += pile / k;
            if (pile % k != 0) ++hours;
            if (hours > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int minSpeed = INT_MAX;

        while (left <= right){
            int mid = (left + right) / 2;

            if (canFinish(piles, h, mid)){ 
                minSpeed = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return minSpeed;
    }
};