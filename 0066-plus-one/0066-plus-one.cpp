class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        ++digits[n - 1];

        if (digits[n - 1] == 10){
            digits[n - 1] = 0;

            for (int i = digits.size() - 2; i >= 0; --i){
                if (digits[i] == 9){
                    digits[i] = 0;
                }
                else {
                    ++digits[i];
                    break;
                }
            }

            if (digits[0] == 0){
                digits.insert(digits.begin(), 1);
            }
        }

        return digits;
    }
};