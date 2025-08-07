class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> pair;
        vector<int> result;

        for (int num : nums2){
            while (!st.empty() && num > st.top()){
                pair[st.top()] = num;
                st.pop();
            }
            
            st.push(num);
        }

        while (!st.empty()){
            pair[st.top()] = -1;
            st.pop();
        }

        for (int num : nums1){
            result.push_back(pair[num]);
        }

        return result;
    }
};