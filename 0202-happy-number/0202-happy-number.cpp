class Solution {
public:
    int calculateSum(int x){
        int sum = 0;

        while (x > 0){
            int digit = x % 10;
            sum += digit * digit;
            x /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sums;
        int sum = calculateSum(n);
        sums.insert(sum);

        while (sum != 1){
            n = sum;
            sum = calculateSum(n);
            
            if (sums.count(sum)){
                return false;
                break;
            }

            sums.insert(sum);
        }

        return true;
    }
};