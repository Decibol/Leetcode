class Solution {
public:
    double myPow(double x, int n) {
        double res = helper(x, n);
        return n > 0 ? res : 1 / res;
    }

    double helper(double x, long n){
        int power = abs(n);
        if (n == 0 || x == 1) return 1;
        if (x == 0) return 0;

        double res = helper(x, floor(power / 2));
        res = res*res;
        return n % 2 == 0 ? res : res*x;
    }
};