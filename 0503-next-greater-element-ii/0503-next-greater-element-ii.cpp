class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n, -1);

        for (int i = 0; i < 2 * n; ++i){
            int index = i % n;
            int num = nums[index];

            while (!st.empty() && num > nums[st.top()]){
                result[st.top()] = num;
                st.pop();
            }

            if (i < n){
                st.push(index);
            }
        }

        return result;
    }
};