class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int beams = 0;

        for (const string &row : bank){
            int cnt = count(row.begin(), row.end(), '1');

            if (cnt > 0){
                beams += prev * cnt;
                prev = cnt;
            }
        }

        return beams;
    }
};