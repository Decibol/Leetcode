class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> result;

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; ++i){
            long long factor = success % spells[i] == 0 ? success / spells[i] : (success / spells[i]) + 1;
            int low = 0;
            int high = m - 1;
            int ans = 0;

            while (low <= high){
                int mid = (low + high) / 2;

                if (potions[mid] < factor){
                    low = mid + 1;
                }
                else {
                    ans = m - mid;
                    high = mid - 1;
                }
            }

            result.push_back(ans);
        }

        return result;
    }
};