class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> charSet = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;

        for (int i = 0; i < s.size(); ++i){
            if (charSet.find(s[i]) != charSet.end()){
                if (st.empty() || st.top() != charSet[s[i]]){
                    return false;
                }
                
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};