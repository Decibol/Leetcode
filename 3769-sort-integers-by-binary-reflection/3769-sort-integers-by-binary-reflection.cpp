class Solution {
public:
    int revInt(int n){
        string s = "";

        while (n > 0){
            s += (n % 2) + '0';
            n /= 2;
        }

        int right = s.size() - 1;
        int ans = 0;
        int power = 0;

        while (right >= 0){
            int num = pow(2, power) * (s[right] - '0');
            ++power;
            ans += num;

            --right;
        }

        return ans;
    }
    
    auto static cmp(pair<int, int>& a, pair<int, int>& b){
        if (a.first == b.first){
            return a.second < b.second;
        }

        return a.first < b.first;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> order;

        for (int x : nums){
            order.push_back({revInt(x), x});
        }
        
        sort(order.begin(), order.end(), cmp);

        vector<int> result;

        for (int i = 0; i < order.size(); ++i){
            result.push_back(order[i].second);
        }

        return result;
    }
};