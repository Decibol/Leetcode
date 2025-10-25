class Solution {
public:
    int totalMoney(int n) {
        int start = 1;
        int currStart = 1;
        int day = 1;
        int total = 0;

        while (day <= n){
            total += currStart;
            ++currStart;

            if (day % 7 == 0){
                ++start;
                currStart = start;
            }

            ++day;
        }

        return total;
    }
};