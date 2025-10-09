class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> finished(n + 1, 0);

        for (auto &m : mana){
            for (int i = 0; i < n; ++i){
                finished[i + 1] = max(finished[i + 1], finished[i]) + 1LL * skill[i] * m;
            }

            for (int i = n - 1; i > 0; --i){
                finished[i] = finished[i + 1] - 1LL * skill[i] * m;
            }
        }

        return finished[n];
    }
};