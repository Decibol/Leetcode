class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (int num : nums){
            while (!st.empty() && gcd(num, st.back()) > 1){
                num = lcm(num, st.back());
                st.pop_back();
            }

            st.push_back(num);
        }

        return st;
    }
};