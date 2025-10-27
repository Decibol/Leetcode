class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices(bank.size());

        for (int i = 0; i < bank.size(); ++i){
            int count = 0;

            for (int j = 0; j < bank[i].size(); ++j){
                if (bank[i][j] == '1') ++count;
            }

            devices[i] = count;
        }

        if (devices.size() == 1) return 0;

        int numBeams = 0;
        int i = 0;

        while (i < devices.size() - 1 && devices[i] == 0) ++i;

        while (i < devices.size() - 1){
            int j = i + 1;

            if (j == i + 1 && devices[j] != 0){
                numBeams += devices[i] * devices[j];
                i = j;
                
                continue;
            }

            while (j < devices.size() - 1 && devices[j] == 0) ++j;

            numBeams += devices[i] * devices[j];
            i = j;
        }

        return numBeams;
    }
};