class Solution {
public:
    bool checkDivisibility(int n){
        while (n > 0){
            if (n % 10 == 0){
                return true;
            }

            n /= 10;
        }

        return false;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - a;

        while (checkDivisibility(b) || checkDivisibility(a)){
            a = a + 1;
            b = n - a;
        }

        return {a, b};
    }
};