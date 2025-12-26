class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> visits(n + 1, 0);

        for (int i = n - 1; i >= 0; --i){
            visits[i] = visits[i + 1];

            if (customers[i] == 'Y'){
                ++visits[i];
            }
        }

        int no_cust = 0;

        for (int i = 0; i <= n; ++i){    
            visits[i] += no_cust;

            if (customers[i] == 'N'){
                ++no_cust;
            }
        }
        
        int idx = 0;
        int minPenalty = INT_MAX;

        for (int i = 0; i <= n; ++i){
            if (visits[i] < minPenalty){
                minPenalty = visits[i];
                idx = i;
            }
        } 

        return idx;
    }
};