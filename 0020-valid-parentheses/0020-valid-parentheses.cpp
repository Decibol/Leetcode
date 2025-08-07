class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pair = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st;

        for (int i = 0; i < s.size(); ++i){
            if (!st.empty() && pair[s[i]] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        } 

        return st.empty();
    }
};