class Solution {
public:
    int numberOfWays(string corridor) {
        if (corridor.size() < 2) return 0;
        int cnt = 0;

        for (char c : corridor){
            if (c == 'S') ++cnt;
        }

        if (cnt < 2 || cnt % 2 != 0) return 0;
        if (cnt == 2) return 1;

        vector<int> plants;
        int i = 0;
        int seats = 0;

        while (i < corridor.size()){
            if (corridor[i] == 'S'){
                ++seats;

                if (seats == 2){
                    int j = i + 1;
                    int count = 0;

                    while (j < corridor.size()){
                        if (corridor[j] == 'P') ++count;
                        else {
                            plants.push_back(count + 1);
                            i = j - 1;
                            seats = 0;
                            count = 0;
                            break;
                        }

                        ++j;
                    }
                }
            }

            ++i;
        }

        long long result = 1;
        long long MOD = 1e9 + 7;
        
        for (int x : plants){
            result = (result * x) % MOD;
        }        

        return result;
    }
};