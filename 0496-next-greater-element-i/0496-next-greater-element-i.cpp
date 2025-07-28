class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        ans.reserve(nums1.size());

        for (int i = 0; i < nums2.size(); ++i){
            st.push(nums2[i]);
        }

        if (st.empty()) return {};

        stack<int> st2 = st;

        for (int i = 0; i < nums1.size(); ++i){
            int topElement = -1;

            while (nums1[i] != st.top()){
                if (nums1[i] < st.top()){
                    topElement = st.top(); 
                }
                st.pop();
            }

            ans.push_back(topElement);
            st = st2;
        }

        return ans;
    }
};