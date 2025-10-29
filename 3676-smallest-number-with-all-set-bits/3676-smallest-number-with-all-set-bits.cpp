class Solution {
public:
    int smallestNumber(int n) {
        int k = 1;
        int num = 1;

        while (true){
            num = 1 << k;
            ++k;
            
            if (num > n) break;
        }

        return num - 1;
    }
};